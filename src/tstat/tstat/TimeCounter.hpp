#pragma once
#include "networking/IServer.hpp"

#include <chrono>
#include <memory>

class TimeCounter
{
    // std::unique_ptr<IServer> server_{};
    std::chrono::time_point<std::chrono::system_clock> start_{};
    std::chrono::time_point<std::chrono::system_clock> stop_{};
    std::string task_name_{};
    bool is_counting_{false};

   public:
    TimeCounter() = default;
    void start(const std::string& task_name);
    void stop();
    void abort();
    void save();
    std::string get_elapsed_time() const;
    std::pair<std::string, std::string> get_file_path() const;
    std::string get_current_state_info() const;
    std::string get_current_task() const;
};
