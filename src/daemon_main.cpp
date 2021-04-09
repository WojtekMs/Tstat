#include <unistd.h>
#include "utils.hpp"
#include "Server.hpp"
#include "config.hpp"
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <iterator>

#include "TimeCounter.hpp"
#include "ArgParser.hpp"
#include "CommandLoader.hpp"

int main() {
    if (daemon(0, 1) == -1) {
        utils::log_error("ERROR while trying to fork!");
    }
    Server daemon_serv(config::SERVER_IP_ADDR, config::SERVER_PORT);
    TimeCounter time_d;
    while(true) {
        daemon_serv.accept_connections();
        auto data = daemon_serv.receive_data();
        try {
            ArgParser args(data);
            CommandLoader loader(time_d, daemon_serv, args.getTask());
            auto command = loader.getCommand(args.getCommand());
            command->execute();
        }
        catch (std::exception& e) {
            std::clog << "server: " << e.what() << '\n';
            continue;
        }
    }   
    return 0; 
}
