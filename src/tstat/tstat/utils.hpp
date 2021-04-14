#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <type_traits>
namespace utils
{
std::vector<std::string> parseArgs(const std::string&);

template < template <typename T> typename Container >
bool contains(const Container<std::string>& container, const std::string& input) {
    return std::find(std::begin(container), std::end(container), input) != std::end(container);
}


}  // namespace utils
