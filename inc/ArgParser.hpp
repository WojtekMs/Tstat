#pragma once

#include <vector>
#include <string>

class ArgParser
{
    std::string command_{};
    std::string task_{};
   public:
    ArgParser() = delete;
    explicit ArgParser(const std::string& input);
    explicit ArgParser(char*[], int);
    std::string getCommand() const;
    std::string getTask() const;
};
