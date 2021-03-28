#include "Server.hpp"
#include "config.hpp"

#include <algorithm>
#include <iostream>

void replying_server(Server & server)
{
    while (true) {
        server.accept_connections();
        auto data = server.receive_data();
        std::string word{"Hello"};
        if (std::search(data.begin(), data.end(), word.begin(), word.end()) !=
            data.end()) {
            std::cout << "client says hi, i think i will reply him" << '\n';
            server.send_data("Hello back, nice to meet you!");

        } else {
            server.send_data(data);
        }
    }
}

int main()
{
    Server server(config::SERVER_IP_ADDR, config::SERVER_PORT);
    while (true) {
        server.accept_connections();
        auto data = server.receive_data();
        std::cout << data << '\n';
        std::cout << "size: " << data.size() << '\n';
    }
}
