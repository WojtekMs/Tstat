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
    Client(const std::string& server_ip_address, int server_port_number);
    ~Client();
    void send_data(const std::string& data) const override;
    std::string receive_data(int char_count = 256) const override;
};
