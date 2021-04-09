#pragma once
#include <vector>
#include <string>

namespace config{
constexpr char SERVER_IP_ADDR[] = "127.0.0.1";
constexpr int SERVER_PORT = 5003;
constexpr char log_save_path[] = "/home/wojtek/networking/tstat/data";
//in bytes / chars
//the first 5 bytes + '\0' contain the size of the message that is being transfered
constexpr int MESSAGE_HEADER_SIZE = 6; 

constexpr char START_COMMAND[] = "start";
constexpr char STOP_COMMAND[] = "stop";
constexpr char ABORT_COMMAND[] = "abort";
// constexpr char SHOW_COMMAND[] = "show";

const std::vector<std::string> UNARY_COMMANDS = {STOP_COMMAND, ABORT_COMMAND}; //, SHOW_COMMAND};
const std::vector<std::string> BINARY_COMMANDS = {START_COMMAND};
const std::vector<std::string> COMMANDS = {START_COMMAND, STOP_COMMAND, ABORT_COMMAND}; //, SHOW_COMMAND};
}
