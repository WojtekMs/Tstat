#pragma once

#include "ICommand.hpp"
#include "TimeCounter.hpp"
#include "IServer.hpp"
#include <string>
#include <memory>

class StartCommand :public ICommand {
    TimeCounter& time_counter_;
    IServer& server_;
    std::string task_name_{};

    public:
    StartCommand(TimeCounter& time_counter, IServer& server, const std::string& task_name);
    void execute() override;
};

std::shared_ptr<ICommand> makeStartCommand(TimeCounter& tc, IServer& server, const std::string& task);
