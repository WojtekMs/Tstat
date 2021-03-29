#pragma once
#include "IServer.hpp"

#include <memory>
#include <chrono>

class TimeDaemon
{
    // std::unique_ptr<IServer> server_{};
    std::chrono::time_point<std::chrono::system_clock> start_{};
    std::chrono::time_point<std::chrono::system_clock> stop_{};

   public:
    TimeDaemon() = default;
    // TimeDaemon(const std::string& server_ip_address, int server_port_number);
    void start();
    void stop();
    void save(const std::string& task_name);
    std::string get_elapsed_time() const;
    std::pair<std::string, std::string> get_file_path(const std::string& task_name) const;

};
