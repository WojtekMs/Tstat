#include "utils.hpp"

#include "config.hpp"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
namespace utils
{
void log_error(const std::string& error_msg)
{
    perror(error_msg.data());
    exit(1);
}

std::unique_ptr<struct pollfd> makePollFd(int poll_fd, short events)
{
    struct pollfd poll {
        .fd = poll_fd
    };
    poll.events |= events;
    return std::make_unique<struct pollfd>(poll);
}

// przyjeto zalozenie, ze nadawca wysyla informacje wraz z '\0'
// przyjeto zalozenie, ze odebrana w ten sposob wiadomosc zapisana w std::string nie
// zawiera juz '\0' kiedy wywolujemy metode .size()
std::string receive_str(int buffer_size, int socket_fd)
{
    auto message_header = utils::receive_string(socket_fd, config::MESSAGE_HEADER_SIZE);
    auto message_size = std::atoi(message_header.c_str());
    auto message = utils::receive_string(socket_fd, message_size);
    return message;
}

std::string receive_string(int socket_fd, int message_size, int recv_flags) {
    int buffer_size = 256;
    char buffer[buffer_size];
    int total_bytes_received{};
    std::string message{};
    while (total_bytes_received < message_size) {
        std::memset(buffer, 0, buffer_size);
        auto bytes_received =
            recv(socket_fd, buffer, message_size - total_bytes_received, recv_flags);
        if (bytes_received == -1) {
            utils::log_error("ERROR on receiving data!");
        }
        if (bytes_received == 0) {
            shutdown(socket_fd, SHUT_RD);
            break;
        }
        total_bytes_received += bytes_received;
        message += std::string(buffer, buffer + strlen(buffer));
    }
    return message;
}


void send_str(const std::string& string, int socket_fd)
{
    if (string.size() < 1) {
        throw std::invalid_argument(
            "Message you are trying to send is too short! Min size: 0");
    }
    if (string.size() > utils::max_message_size()) {
        throw std::invalid_argument(
            "Message you are trying to send is too long! Max size: " +
            std::to_string(utils::max_message_size()));
    }
    utils::send_string(utils::get_message_header(string.size() + 1), socket_fd);
    utils::send_string(string, socket_fd);
}

void send_string(const std::string& string, int socket_fd, int send_flags)
{
    // after sending some bytes you have to remove the bytes from the buffer
    int total_bytes_sent{};
    std::string message{string};
    int message_size = message.size() + 1;
    while (total_bytes_sent < message_size) {
        auto bytes_sent = send(socket_fd,
                               message.c_str(),
                               message_size - total_bytes_sent,
                               send_flags);
        if (bytes_sent == -1) {
            utils::log_error("ERROR on sending data to the server!");
        }
        total_bytes_sent += bytes_sent;
        if (bytes_sent < message_size) {
            message.erase(message.begin(),
                                std::min(std::next(message.begin(), bytes_sent),
                                        message.end()));
        }
    }
}

int max_message_size()
{
    std::string max_msg_value{};
    for (int i = 0; i < config::MESSAGE_HEADER_SIZE; ++i) {
        max_msg_value += '9';
    }
    return std::atoi(max_msg_value.c_str());
}

std::string get_message_header(int message_size)
{
    std::string header = std::to_string(message_size);
    int zero_padding = config::MESSAGE_HEADER_SIZE - (header.size() + 1);
    for (int i = 0; i < zero_padding; i++) {
        header.insert(header.begin(), '0');
    }
    return header;
}

}  // namespace utils
