#include "Server.hpp"

#include "utils.hpp"

#include <thread>
#include <iostream>

#include <arpa/inet.h>
#include <stdexcept>
#include <string.h>
#include <sys/socket.h>
#include <cstring>
#include <poll.h>
#include <unistd.h>
#include <fcntl.h>

Server::Server(const std::string& ip_address, int port_number) :
  ip_address_(ip_address),
  port_number_(port_number)
{
    std::cout << "Starting server on IP: " << ip_address << ", port: " << port_number
              << '\n';
    // create a socket
    server_socket_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd_ < 0) {
        utils::log_error("ERROR opening socket");
    }

    /* setup the host_address (server address) structure for use in bind call */
    // clear address structure
    bzero((char*)&server_address_, sizeof(server_address_));
    // server byte order (internet socket -> TCP/IP or UDP)
    server_address_.sin_family = AF_INET;
    // integer value for port must be converted into network byte order which is unified
    server_address_.sin_port = htons(port_number_);
    // fill in ip address to the server address structure
    if (inet_aton(ip_address_.data(), &server_address_.sin_addr) == 0) {
        utils::log_error("Wrong IP Addres: " + ip_address_);
    }

    // This bind() call will bind the socket to the current IP address on port, portno
    if (bind(server_socket_fd_,
             reinterpret_cast<struct sockaddr*>(&server_address_),
             sizeof(server_address_)) < 0) {
        utils::log_error("ERROR on binding");
    }

    int queue_size = 5;
    if (listen(server_socket_fd_, queue_size) == -1) {
        utils::log_error("ERROR on listening");
    }
}

void Server::accept_connections()
{
    socklen_t client_socket_size{sizeof(client_address_)};
    client_socket_fd_ = accept(server_socket_fd_,
                               (struct sockaddr*)&client_address_,
                               &client_socket_size);
    if (client_socket_fd_ < 0) {
        utils::log_error("ERROR on accept");
    }
    // fcntl(client_socket_fd_, F_SETFL, O_NONBLOCK);
    std::cout << "Server: received connection from "
              << inet_ntoa(client_address_.sin_addr) << " port "
              << ntohs(client_address_.sin_port) << '\n';
}

void Server::send_data(const std::string& data) const
{
    if (client_socket_fd_ < 0) {
        throw std::logic_error(
            "Client socket is not valid, make sure you accepted connection first!\n");
    }
    utils::send_str(data, client_socket_fd_);
}

std::string Server::receive_data(int buffer_size) const
{
    if (client_socket_fd_ < 0) {
        throw std::logic_error(
            "Client socket is not valid, make sure you accepted connection first!\n");
    }

    return utils::receive_str(buffer_size, client_socket_fd_);
}

Server::~Server()
{
    close(server_socket_fd_);
    close(client_socket_fd_);
}
