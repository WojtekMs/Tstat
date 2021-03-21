#pragma once
#include "IServer.hpp"

#include <memory>

class TimeDaemon
{
    std::unique_ptr<IServer> server{};

   public:
    TimeDaemon(const std::string& server_ip_address, int server_port_number);
};
