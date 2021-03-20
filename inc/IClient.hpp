#pragma once

#include <string>

class IClient
{
   public:
    virtual void send_data(const std::string&) const = 0;
    virtual std::string receive_data(int) const = 0;
    virtual ~IClient() = 0;
};
