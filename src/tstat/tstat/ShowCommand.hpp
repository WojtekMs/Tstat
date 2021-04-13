#pragma once

#include "networking/IServer.hpp"
#include "tstat/ICommand.hpp"
#include "tstat/TimeCounter.hpp"
#include <memory>

class ShowCommand : public ICommand {
    TimeCounter& counter_;
    networking::IServer& server_;

    public:
    ShowCommand(TimeCounter& tc, networking::IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeShowCommand(TimeCounter& tc, networking::IServer& server, const std::string& = "");
