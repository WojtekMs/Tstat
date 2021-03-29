#include "Client.hpp"
#include "config.hpp"
#include <algorithm>
#include <iostream>

#include <ctime>
#include <iomanip>
#include "TimeDaemon.hpp"
#include <thread>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << argv[0] << "task_name <studia/racing> command <start/stop>\n";
        return 0;
    }
    Client client(config::SERVER_IP_ADDR, config::SERVER_PORT);
    std::string argument{argv[1]};
    std::string stop_command{"stop"};
    std::string start_command{"start"};
    std::string data = std::string(argv[1]) + " " + std::string(argv[2]);
    client.send_data(data);
    // if (std::search(argument.begin(), argument.end(), start_command.begin(), start_command.end()) != argument.end()) {
    //     // client.send_data("start");
    // }
    if (std::search(argument.begin(), argument.end(), stop_command.begin(), stop_command.end()) != argument.end()) {
        // client.send_data("stop");
        std::cout << client.receive_data() << '\n';
    }
}
