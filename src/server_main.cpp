#include "Server.hpp"
#include "config.hpp"
#include <iostream>

int main() {
    Server server(SERVER_IP_ADDR, SERVER_PORT);
    server.accept_connections();
    std::cout << server.receive_data() << '\n';
    server.send_data("What are you doing now?");
}
