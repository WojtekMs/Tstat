#include "tstat/utils.hpp"

#include <cstring>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
namespace utils
{
// std::unique_ptr<struct pollfd> makePollFd(int poll_fd, short events)
// {
//     struct pollfd poll {
//         .fd = poll_fd
//     };
//     poll.events |= events;
//     return std::make_unique<struct pollfd>(poll);
// }

std::vector<std::string> parseArgs(const std::string& data) {
    std::stringstream stream{};
    stream.str(data);
    std::vector<std::string> args{};
    std::copy(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>{}, std::back_inserter(args));
    return args;
}

}  // namespace utils
