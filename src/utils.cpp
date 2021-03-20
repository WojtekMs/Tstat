#include "utils.hpp"
#include "stdio.h"
#include "stdlib.h"

void utils::log_error(const std::string& error_msg)
{
    perror(error_msg.data());
    exit(1);
}
