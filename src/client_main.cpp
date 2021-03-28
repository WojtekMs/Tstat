#include "Client.hpp"
#include "config.hpp"
#include <iostream>

std::string manual(const std::string& program_name) {
    return "usage " + program_name + " string to send\n";
}

int main(int argc, char* argv[]) {
    if (argc <= 1 or argc > 2) {
        std::cout << manual(argv[0]);
        return 0;
    }
    Client client(config::SERVER_IP_ADDR, config::SERVER_PORT);
    client.send_data(argv[1]);
}
