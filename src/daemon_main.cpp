#include <unistd.h>
#include "utils.hpp"
#include "Server.hpp"
#include "config.hpp"
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iostream>

int main() {
    if (daemon(0, 0) == -1) {
        utils::log_error("ERROR while trying to fork!");
    }
    Server daemon_serv(config::SERVER_IP_ADDR, config::SERVER_PORT);
    auto start = std::chrono::steady_clock::now();
    while(true) {
        daemon_serv.accept_connections();
        auto data = daemon_serv.receive_data();
        std::string start_flag{"start"};
        std::string stop_flag{"stop"};
        if (std::search(data.begin(), data.end(), start_flag.begin(), start_flag.end()) != data.end()) {
            start = std::chrono::steady_clock::now();
        }
        if (std::search(data.begin(), data.end(), stop_flag.begin(), stop_flag.end()) != data.end()) {
            auto stop = std::chrono::steady_clock::now();
            std::stringstream stream{};
            stream << "Time elapsed: " << std::chrono::duration<double>(stop - start).count() << "s\n";
            daemon_serv.send_data(stream.str());
        }
    }   
    return 0; 
}
