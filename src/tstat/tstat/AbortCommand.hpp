#pragma once

#include "networking/IServer.hpp"
#include "tstat/ICommand.hpp"
#include "tstat/TimeCounter.hpp"
#include <string>
#include <memory>

class AbortCommand : public ICommand {
    TimeCounter& time_counter_;
    networking::IServer& server_;

    public:
    AbortCommand(TimeCounter& time_counter, networking::IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeAbortCommand(TimeCounter& tc, networking::IServer& server, const std::string& task = "");
