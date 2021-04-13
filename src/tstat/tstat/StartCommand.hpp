#pragma once

#include "tstat/ICommand.hpp"
#include "tstat/TimeCounter.hpp"
#include "networking/IServer.hpp"
#include <string>
#include <memory>

class StartCommand :public ICommand {
    TimeCounter& time_counter_;
    networking::IServer& server_;
    std::string task_name_{};

    public:
    StartCommand(TimeCounter& time_counter, networking::IServer& server, const std::string& task_name);
    void execute() override;
};

std::shared_ptr<ICommand> makeStartCommand(TimeCounter& tc, networking::IServer& server, const std::string& task);
