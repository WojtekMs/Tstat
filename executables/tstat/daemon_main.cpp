#include "networking/Server.hpp"
#include "networking/config.hpp"
#include "networking/utils.hpp"
#include "tstat/ArgParser.hpp"
#include "tstat/CommandLoader.hpp"
#include "tstat/TimeCounter.hpp"

#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <unistd.h>

int main()
{
    if (daemon(0, 1) == -1) {
        networking::utils::log_error("ERROR while trying to fork!");
    }
    networking::Server daemon_serv(networking::config::SERVER_IP_ADDR,
                                   networking::config::SERVER_PORT);
    TimeCounter time_d;
    while (true) {
        daemon_serv.accept_connections();
        auto data = daemon_serv.receive_data();
        try {
            ArgParser args(data);
            CommandLoader loader(time_d, daemon_serv, args.getCommandArgs());
            auto command = loader.getCommand(args.getCommand());
            command->execute();
        } catch (std::exception& e) {
            std::clog << "server: " << e.what() << '\n';
            continue;
        }
    }
    return 0;
}
