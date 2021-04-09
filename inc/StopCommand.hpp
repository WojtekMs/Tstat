#pragma once

#include "ICommand.hpp"
#include "IServer.hpp"
#include "TimeCounter.hpp"
#include <memory>

class StopCommand : public ICommand
{
    TimeCounter& counter_;
    IServer& server_;

   public:
    StopCommand() = delete;
    StopCommand(TimeCounter& tc, IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeStopCommand(TimeCounter& tc, IServer& server, const std::string& = "");
