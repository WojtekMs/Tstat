#include <unistd.h>
#include "utils.hpp"
#include "Server.hpp"
#include "config.hpp"
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <iterator>

#include "TimeDaemon.hpp"

int main() {
    if (daemon(0, 1) == -1) {
        utils::log_error("ERROR while trying to fork!");
    }
    Server daemon_serv(config::SERVER_IP_ADDR, config::SERVER_PORT);
    TimeDaemon time_d;
    while(true) {
        daemon_serv.accept_connections();
        auto data = daemon_serv.receive_data();
        std::cout << data << '\n';
        std::stringstream stream(data);
        std::vector<std::string> args{};
        std::copy(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>{}, std::back_inserter(args));
        std::string start_flag{"start"};
        std::string stop_flag{"stop"};
        std::string task_name{args[0]};
        std::string command{args[1]};
        if (command == start_flag) {
            time_d.start();
        }
        if (command == stop_flag) {
            time_d.stop();
            time_d.save(task_name);
            stream.str("");
            stream << "Time elapsed: " << time_d.get_elapsed_time() << '\n';
            stream << "Saved to file: " << time_d.get_file_path(task_name).second << '\n';
            daemon_serv.send_data(stream.str());
            std::cout << stream.str() << '\n';
        }
    }   
    return 0; 
}
