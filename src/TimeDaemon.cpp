#include "TimeDaemon.hpp"

#include "config.hpp"

#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

void TimeDaemon::save(const std::string& task_name)
{
    auto [file_name, file_path] = get_file_path(task_name);
    std::string task_directory = std::string(config::log_save_path) + "/" + task_name;
    if (!std::filesystem::exists(task_directory)) {
        std::filesystem::create_directories(task_directory);
    }
    std::ios_base::openmode file_flags{};
    if (std::filesystem::exists(file_path)) {
        file_flags = std::ios_base::out | std::ios_base::app;
    }
    std::ofstream output_file(file_path, file_flags);
    output_file << get_elapsed_time() << '\n';
}

std::pair<std::string, std::string> TimeDaemon::get_file_path(
    const std::string& task_name) const
{
    std::string file_name{};
    std::stringstream stream{};
    auto time = std::time(nullptr);
    stream << std::put_time(std::localtime(&time), "%d_%m_%Y");
    file_name = stream.str();
    stream.str("");
    stream << config::log_save_path << "/" << task_name << "/" << file_name;
    std::string file_path{stream.str()};
    return std::make_pair(file_name, file_path);
}

void TimeDaemon::start()
{
    start_ = std::chrono::system_clock::now();
}

void TimeDaemon::stop()
{
    stop_ = std::chrono::system_clock::now();
}

std::string TimeDaemon::get_elapsed_time() const
{
    std::stringstream stream{};
    auto seconds =
        std::chrono::duration_cast<std::chrono::seconds>(stop_ - start_).count();
    auto minutes = seconds / 60;
    auto hours = minutes / 60;
    seconds %= 60;
    if (hours < 10) {
        stream << 0;
    }
    stream << hours << ":";
    if (minutes < 10) {
        stream << 0;
    }
    stream << minutes << ":";
    if (seconds < 10) {
        stream << 0;
    }
    stream << seconds;
    return stream.str();
}
