#pragma once

#include <string>
namespace networking
{
class IClient
{
   public:
    virtual void send_data(const std::string& data) const = 0;
    virtual std::string receive_data(int char_count) const = 0;
    virtual ~IClient() = default;
};
}  // namespace networking
