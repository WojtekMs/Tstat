#pragma once
#include <string>
#include <memory>
#include <poll.h>
namespace utils
{
void log_error(const std::string& error_msg);
std::unique_ptr<struct pollfd> makePollFd(int poll_fd, short events);

/**
 * @brief this function is used to receive char data from stream sockets
 * this function reads characters from the stream until the first occurence of '\0'
 * 
 * @param buffer_size 
 * @param socket_fd 
 * @return std::string 
 */
std::string receive_str(int buffer_size, int socket_fd);

/**
 * @brief this functions is used to send char data by stream socket
 * this function makes sure that all bytes were sent out, it sends out c style string (null terminated)
 * 
 * @param string 
 * @param socket_fd 
 */
void send_str(const std::string& string, int socket_fd);

template <typename Array>
constexpr int array_size(const Array& arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}
}  // namespace utils
