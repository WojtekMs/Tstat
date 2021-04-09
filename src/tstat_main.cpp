#include "Client.hpp"
#include "config.hpp"
#include <algorithm>
#include <iostream>

#include <ctime>
#include <iomanip>
#include "TimeCounter.hpp"
#include "ArgParser.hpp"
#include <thread>

int main(int argc, char* argv[]) {
    Client client(config::SERVER_IP_ADDR, config::SERVER_PORT);
    try {
        ArgParser args(argv, argc);
        std::string data = args.getCommand() + " " + args.getTask();
        std::cout << data << '\n';
        client.send_data(data);
        std::cout << client.receive_data() << '\n';
    }
    catch(std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
