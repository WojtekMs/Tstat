#include "networking/Client.hpp"
#include "networking/config.hpp"
#include "tstat/ArgParser.hpp"
#include "tstat/TimeCounter.hpp"

#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>

int main(int argc, char* argv[])
{
    networking::Client client(networking::config::SERVER_IP_ADDR,
                              networking::config::SERVER_PORT);
    try {
        ArgParser args(argv, argc);
        client.send_data(args.getArgsAsString());
        std::cout << client.receive_data() << '\n';
    } catch (std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
