#pragma once

#include <string>
#include <vector>
#include <algorithm>
namespace utils
{
std::vector<std::string> parseArgs(const std::string&);

template <typename Container>
bool contains(const Container& container, const std::string& input) {
    return std::find(std::begin(container), std::end(container), input) != std::end(container);
}


}  // namespace utils
