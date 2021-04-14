#pragma once
#include <vector>
#include <string>

namespace config{

constexpr char START_COMMAND[] = "start";
constexpr char STOP_COMMAND[] = "stop";
constexpr char ABORT_COMMAND[] = "abort";
constexpr char SHOW_COMMAND[] = "show";
constexpr char log_save_path[] = "/home/wojtek/networking/tstat/data";

const std::vector<std::string> UNARY_COMMANDS = {STOP_COMMAND, ABORT_COMMAND, SHOW_COMMAND};
const std::vector<std::string> BINARY_COMMANDS = {START_COMMAND};
const std::vector<std::string> COMMANDS = {START_COMMAND, STOP_COMMAND, ABORT_COMMAND, SHOW_COMMAND};
}
