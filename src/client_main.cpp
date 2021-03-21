#include "Client.hpp"
#include "config.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    Client client(config::SERVER_IP_ADDR, config::SERVER_PORT);
    client.send_data(argv[1]);
    std::cout << client.receive_data() << '\n';
}
