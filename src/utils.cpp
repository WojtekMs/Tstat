#include "utils.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sys/socket.h>
#include <iostream>
#include <string>

namespace utils {
    
void log_error(const std::string& error_msg)
{
    perror(error_msg.data());
    exit(1);
}

std::unique_ptr<struct pollfd> makePollFd(int poll_fd, short events) {
    struct pollfd poll{.fd = poll_fd};
    poll.events |= events;
    return std::make_unique<struct pollfd>(poll);
}

std::string receive_str(int buffer_size, int socket_fd) {
    std::string message{};
    ssize_t bytes_received{};
    char buffer[buffer_size];
    int recv_flags{};
    do {
        std::memset(buffer, 0, buffer_size);
        bytes_received = recv(socket_fd, buffer, buffer_size, recv_flags);
        if (bytes_received == -1) {
                utils::log_error("ERROR on receiving data!");
            }
        message += std::string(buffer, buffer + bytes_received);
        std::cout << "bytes received: " << bytes_received << '\n';
        if (auto pos = message.find('\0'); pos != std::string::npos) {
            return message.substr(0, message.find('\0')); 
        }
    }
    while(bytes_received != 0);

    return message + '\0';

}

void send_str(const std::string& string, int socket_fd) {
    int send_flags{};
    ssize_t total_bytes_sent{};
    do {
        auto bytes_sent = send(socket_fd, string.c_str(), string.size() + 1, send_flags);
        if (bytes_sent == -1) {
            utils::log_error("ERROR on sending data to the server!");
        }
        total_bytes_sent += bytes_sent;

    }
    while (total_bytes_sent != string.size() + 1);

}

}
