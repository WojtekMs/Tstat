#pragma once

#include <string>

class IClient
{
   public:
    virtual void send_data(const std::string& data) const = 0;
    virtual std::string receive_data(int char_count, bool non_blocking) const = 0;
    virtual ~IClient() = default;
};
