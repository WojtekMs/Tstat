#include "tstat/CommandLoader.hpp"

CommandLoader::CommandLoader(TimeCounter& tc, networking::IServer& server, const std::string& task) :
  counter_(tc),
  server_(server),
  task_(task)
{
}

std::shared_ptr<ICommand> CommandLoader::getCommand(const std::string& command) const
{
    return commands_.at(command)(counter_, server_, task_);
}
