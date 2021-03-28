#include "Client.hpp"
#include "config.hpp"
#include <algorithm>
#include <iostream>

int main(int argc, char* argv[]) {
    Client client(config::SERVER_IP_ADDR, config::SERVER_PORT);
    std::string argument{argv[1]};
    std::string stop_command{"stop"};
    std::string start_command{"start"};
    if (std::search(argument.begin(), argument.end(), start_command.begin(), start_command.end()) != argument.end()) {
        client.send_data("start");
        std::cout << client.receive_data(256) << '\n';
    }
    if (std::search(argument.begin(), argument.end(), stop_command.begin(), stop_command.end()) != argument.end()) {
        client.send_data("stop");
        std::cout << client.receive_data() << '\n';
    }
}
