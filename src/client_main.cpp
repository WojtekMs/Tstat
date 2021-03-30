#include "Client.hpp"
#include "config.hpp"

#include <iostream>

std::string manual(const std::string& program_name)
{
    return "usage " + program_name + " string to send\n";
}

void send_cli_args(int argc, char* argv[])
{
    if (argc <= 1 or argc > 2) {
        std::cout << manual(argv[0]);
        return;
    }
    Client client(config::SERVER_IP_ADDR, config::SERVER_PORT);
    client.send_data(argv[1]);
}

int main(int argc, char* argv[])
{
    Client client(config::SERVER_IP_ADDR, config::SERVER_PORT);
    std::string input{};
    while (true) {
        std::getline(std::cin, input);
        client.send_data(input);
    }

}
