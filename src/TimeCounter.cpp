#include "TimeCounter.hpp"

#include "config.hpp"

#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

void TimeCounter::save()
{
    auto [file_name, file_path] = get_file_path();
    std::string task_directory = std::string(config::log_save_path) + "/" + task_name_;
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

std::pair<std::string, std::string> TimeCounter::get_file_path() const
{
    std::string file_name{};
    std::stringstream stream{};
    auto time = std::time(nullptr);
    stream << std::put_time(std::localtime(&time), "%d_%m_%Y");
    file_name = stream.str();
    stream.str("");
    stream << config::log_save_path << "/" << task_name_ << "/" << file_name;
    std::string file_path{stream.str()};
    return std::make_pair(file_name, file_path);
}

void TimeCounter::start(const std::string& task_name)
{
    if (is_counting_) {
        throw std::logic_error("Counter is already started!");
    }
    task_name_ = task_name;
    start_ = std::chrono::system_clock::now();
    is_counting_ = true;
}

void TimeCounter::abort() {
    if (!is_counting_) {
        throw std::logic_error("Counter is not started, it cannot be stopped!");
    }
    is_counting_ = false;
    task_name_.clear();
}

void TimeCounter::stop()
{
    if (!is_counting_) {
        throw std::logic_error("Counter is not started, it cannot be stopped!");
    }
    stop_ = std::chrono::system_clock::now();
    is_counting_ = false;
}

std::string TimeCounter::get_elapsed_time() const
{
    std::stringstream stream{};
    auto seconds =
        std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start_).count();
    auto minutes = seconds / 60;
    auto hours = minutes / 60;
    seconds %= 60;
    minutes %= 60;
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

std::string TimeCounter::get_current_state_info() const {
    std::stringstream stream{};
    stream << "State: ";
    if (is_counting_) {
        stream << "counting\n";
    } else {
        stream << "not counting\n";
    }
    stream << "Task: " << task_name_ << '\n';
    stream << "Time elapsed: " << get_elapsed_time();
    return stream.str();
}

std::string TimeCounter::get_current_task() const {
    return task_name_;
}

