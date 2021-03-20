#pragma once
#include "IServer.hpp"

#include <netinet/in.h>
#include <string>

/**
 * @brief Server class, wrapper for TCP/IP Server/Client communication
 * we have to state IP_Address of the server (??however it is localhost??)
 * we have to state port number on which the application will be running
 * this can be verified by running `netstat -tulpn` when server is accepting connections
 *
 * This class creates a socket bound to given ip address and port number,
 * you can activate accepting connections, then server will be actively waiting for
 * clients after the connection is started you can send or receive character data from
 * client
 */
class Server : public IServer
{
    std::string ip_address_{};
    int port_number_{};
    int server_socket_fd_{-1};
    int client_socket_fd_{-1};
    struct sockaddr_in server_address_ {
    };
    struct sockaddr_in client_address_ {
    };

   public:
    Server(const std::string& ip_address, int port_number);
    ~Server();
    void accept_connections() override;
    void send_data(const std::string& data) const override;
    std::string receive_data(int char_count = 256) const override;
};
