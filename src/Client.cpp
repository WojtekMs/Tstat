#include "Client.hpp"

#include "utils.hpp"

#include <arpa/inet.h>
#include <bits/socket.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

void Client::setup_server_socket(const std::string& server_ip_address,
                                 int server_port_number)
{
    std::cout << "Connecting to server on IP: " << server_ip_address
              << ", port: " << server_port_number << '\n';
    server_socket_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd_ < 0) {
        utils::log_error("ERROR on creating a socket!");
    }
    bzero(&server_socket_, sizeof(server_socket_));
    if (inet_aton(server_ip_address.data(), &server_socket_.sin_addr) < 0) {
        utils::log_error("ERROR ip address could not be converted to binary format!");
    }
    server_socket_.sin_family = AF_INET;
    server_socket_.sin_port = htons(server_port_number);
}

Client::Client(const std::string& server_ip_address, int server_port_number)
{
    setup_server_socket(server_ip_address, server_port_number);
    socklen_t server_socket_len = sizeof(server_socket_);
    if (connect(server_socket_fd_,
                reinterpret_cast<struct sockaddr*>(&server_socket_),
                server_socket_len) < 0) {
        utils::log_error("ERROR on connecting to server!");
    }
    std::cout << "Client: connection to server " << inet_ntoa(server_socket_.sin_addr)
              << ", on port " << ntohs(server_socket_.sin_port)
              << " established succesfully!\n";
}


void Client::send_data(const std::string& data) const
{
    if (data.size())
    utils::send_str(data, server_socket_fd_);
}

std::string Client::receive_data(int buffer_size) const
{
    return utils::receive_str(buffer_size, server_socket_fd_);
}

Client::~Client()
{
    close(server_socket_fd_);
}

void Client::terminate_connection() {
    close(server_socket_fd_);
}
