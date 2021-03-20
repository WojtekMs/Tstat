#pragma once
#include <string>

namespace utils
{
void log_error(const std::string& error_msg);

template <typename Array>
constexpr int array_size(const Array& arr)
{
    return sizeof(arr) / sizeof(arr[0]);
}
}  // namespace utils
