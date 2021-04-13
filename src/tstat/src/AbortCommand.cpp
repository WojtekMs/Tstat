#include "tstat/AbortCommand.hpp"

#include <sstream>

AbortCommand::AbortCommand(TimeCounter& time_counter, networking::IServer& server) :
  time_counter_(time_counter),
  server_(server)
{
}

void AbortCommand::execute()
{
  try {
    time_counter_.abort();
  }
  catch (std::logic_error& e) {
    server_.send_data(e.what());
    return;
  }
  std::stringstream stream{};
  stream << "Counter aborted!\n";
  server_.send_data(stream.str());
}

std::shared_ptr<ICommand> makeAbortCommand(TimeCounter& tc, networking::IServer& server, const std::string&) {
    return std::make_shared<AbortCommand>(tc, server);
}
