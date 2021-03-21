#pragma once

#include <string>

class IServer
{
   public:
    virtual void accept_connections() = 0;
    virtual void send_data(const std::string& data) const = 0;
    virtual std::string receive_data(int char_count) const = 0;
    virtual ~IServer() = default;
};
