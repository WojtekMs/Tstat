#pragma once

#include <memory>
#include <string>
#include "tstat/ICommand.hpp"

class TimeCounter;

namespace networking
{
class IServer;
}
class ShowCommand : public ICommand
{
    TimeCounter& counter_;
    networking::IServer& server_;

   public:
    ShowCommand(TimeCounter& tc, networking::IServer& server);
    void execute() override;
};

std::shared_ptr<ICommand> makeShowCommand(TimeCounter& tc,
                                          networking::IServer& server,
                                          const std::string& = {});
