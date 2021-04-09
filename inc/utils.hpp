#pragma once

#include <memory>
#include <poll.h>
#include <string>
#include <vector>
#include <algorithm>
namespace utils
{
void log_error(const std::string& error_msg);
std::unique_ptr<struct pollfd> makePollFd(int poll_fd, short events);
std::vector<std::string> parseArgs(const std::string&);

template <typename Container>
bool contains(const Container& container, const std::string& input) {
    return std::find(std::begin(container), std::end(container), input) != std::end(container);
}

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
 * this function makes sure that all bytes were sent out, it sends out c style string
 * (null terminated)
 *
 * @param string
 * @param socket_fd
 */
void send_str(const std::string& string, int socket_fd);

void send_string(const std::string& string, int socket_fd, int send_flags = 0);
std::string receive_string(int socket_fd, int message_size, int send_flags = 0);

int max_message_size();
std::string get_message_header(int message_size);

template <typename Array>
constexpr int array_size(const Array& arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}
}  // namespace utils
