#pragma once

// #include <memory>
// #include <poll.h>
#include <string>
#include <vector>
#include <algorithm>
namespace utils
{
// std::unique_ptr<struct pollfd> makePollFd(int poll_fd, short events);
std::vector<std::string> parseArgs(const std::string&);

template <typename Container>
bool contains(const Container& container, const std::string& input) {
    return std::find(std::begin(container), std::end(container), input) != std::end(container);
}

// template <typename Array>
// constexpr int array_size(const Array& arr)
// {
//     return sizeof(arr) / sizeof(arr[0]);
// }

}  // namespace utils
