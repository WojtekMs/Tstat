#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
namespace utils
{
using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

std::string getElapsedTime(const TimePoint& stop, const TimePoint& start);
std::string getCurrentDate();
std::vector<std::string> parseArgs(const std::string&);

template <typename ...T>
std::string join(char sign, T&&... args) {
    std::string joined_str = ((std::string(args) + sign) + ...);
    joined_str.erase(std::prev(joined_str.end()));
    return joined_str;
}

template < template <typename T> typename Container >
bool contains(const Container<std::string>& container, const std::string& input) {
    return std::find(std::begin(container), std::end(container), input) != std::end(container);
}


}  // namespace utils
