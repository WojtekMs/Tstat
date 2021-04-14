#include "tstat/CommandLoader.hpp"

CommandLoader::CommandLoader(TimeCounter& tc, networking::IServer& server, const std::vector<std::string>& args) :
  counter_(tc),
  server_(server),
  args_(args)
{
}

std::shared_ptr<ICommand> CommandLoader::getCommand(const std::string& command) const
{
    return commands_.at(command)(counter_, server_, args_);
}
