#include "ArgParser.hpp"

#include "utils.hpp"
#include "config.hpp"
#include <stdexcept>

ArgParser::ArgParser(const std::string& input) {
    auto args = utils::parseArgs(input);
    if (args.empty()) {
        throw std::logic_error("At least one argument is necessary!");
    }
    if (!utils::contains(config::COMMANDS, args[0])) {
        throw std::invalid_argument("First argument must be command!");
    }
    if (args.size() < 2 && utils::contains(config::BINARY_COMMANDS, args[1])) {
        throw std::invalid_argument("Command: " + args[1] + " requires second argument!");
    }
    if (args.size() > 1) {
        task_ = args[1];
    }
    command_ = args[0];
}

ArgParser::ArgParser(char* argv[], int argc) {
    if (argc == 1) {
        throw std::logic_error("At least one argument is necessary!");
    }
    if (!utils::contains(config::COMMANDS, argv[1])) {
        throw std::invalid_argument("First argument must be command!");
    }
    if (argc < 3 && utils::contains(config::BINARY_COMMANDS, argv[1])) {
        throw std::invalid_argument("Command: " + std::string(argv[1]) + " requires second argument!");
    }
    if (argc > 2) {
        task_ = argv[2];
    }
    command_ = argv[1];
}

std::string ArgParser::getTask() const {
    return task_;
}

std::string ArgParser::getCommand() const {
    return command_;
}
