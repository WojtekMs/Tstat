#include "Client.hpp"
#include "config.hpp"
#include <iostream>

int main() {
    Client client(SERVER_IP_ADDR, SERVER_PORT);
    client.send_data("Client says hi!\n");
    std::cout << client.receive_data() << '\n';
}
