#pragma once

#include "networking/IServer.hpp"
#include "tstat/ICommand.hpp"
#include "tstat/TimeCounter.hpp"
#include <memory>

class StopCommand : public ICommand
{
    TimeCounter& counter_;
    networking::IServer& server_;

   public:
    StopCommand() = delete;
    StopCommand(TimeCounter& tc, networking::IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeStopCommand(TimeCounter& tc, networking::IServer& server, const std::string& = "");
