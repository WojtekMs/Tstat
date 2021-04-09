#pragma once

#include "ICommand.hpp"
#include "TimeCounter.hpp"
#include "IServer.hpp"
#include <string>
#include <memory>

class AbortCommand : public ICommand {
    TimeCounter& time_counter_;
    IServer& server_;

    public:
    AbortCommand(TimeCounter& time_counter, IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeAbortCommand(TimeCounter& tc, IServer& server, const std::string& task = "");
