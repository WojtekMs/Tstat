#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include <memory>

#include "networking/IServer.hpp"
#include "tstat/StartCommand.hpp"
#include "tstat/StopCommand.hpp"
#include "tstat/AbortCommand.hpp"
// #include "ShowCommand.hpp"
#include "tstat/TimeCounter.hpp"
#include "tstat/config.hpp"

class ICommand;

class CommandLoader
{
    TimeCounter& counter_;
    networking::IServer& server_;
    std::string task_{};
    std::unordered_map<std::string, std::function<std::shared_ptr<ICommand>(TimeCounter&, networking::IServer&, const std::string&)>> commands_{
        std::make_pair(config::START_COMMAND, makeStartCommand),
        std::make_pair(config::STOP_COMMAND, makeStopCommand),
        std::make_pair(config::ABORT_COMMAND, makeAbortCommand),
        // std::make_pair(config::SHOW_COMMAND, makeShowCommand)
    };
   public:
    CommandLoader() = delete;
    CommandLoader(TimeCounter&, networking::IServer&, const std::string&);
    std::shared_ptr<ICommand> getCommand(const std::string& command) const;
};
