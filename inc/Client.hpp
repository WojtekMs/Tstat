#pragma once
#include "IClient.hpp"

#include <netinet/in.h>
#include <string>

/**
 * @brief Client class, wrapper for TCP/IP communication.
 * You have to state server IP addres and server port number on which you want to connect
 * to the server Client is creating a socket to connect to the server, after the socket is
 * initialized client connects to the server through the socket. Client IP address and
 * client port number are not very important, client port number is chosen by OS
 *
 * After the connection is established you can send and receive character data
 *
 */
class Client : public IClient
{
    int server_socket_fd_{-1};
    struct sockaddr_in server_socket_ {
    };

    void setup_server_socket(const std::string& server_ip_address,
                             int server_port_number);

   public:
    Client() = delete;
    Client(const std::string& server_ip_address, int server_port_number);
    Client(const Client&) = delete;
    Client(Client&&) = delete;
    Client& operator=(const Client&) = delete;
    Client& operator=(Client&&) = delete;
    ~Client() override;
    void send_data(const std::string& data) const override;
    std::string receive_data(int buffer_size = 256) const override;
};
