#pragma once

#include <string>

class IServer
{
   public:
    virtual void accept_connections() = 0;
    virtual void send_data(const std::string&) const = 0;
    virtual std::string receive_data(int) const = 0;
    virtual ~IServer() = 0;
};
