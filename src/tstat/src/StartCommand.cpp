#include "tstat/StartCommand.hpp"
#include "tstat/CommandError.hpp"

#include <sstream>

StartCommand::StartCommand(TimeCounter& time_counter, networking::IServer& server, const std::vector<std::string>& args) :
  time_counter_(time_counter),
  server_(server)
{
  if (args.size() != 1) {
    throw CommandError("Start command needs one argument: task name!");
  }
  task_name_ = args[0];
}

void StartCommand::execute()
{
  try {
    time_counter_.start(task_name_);
  }
  catch (std::logic_error& e) {
    server_.send_data(e.what());
    return;
  }
    std::stringstream stream{};
    stream << "Counter started!\n";
    stream << "Task: " << time_counter_.get_current_task() << '\n';
    server_.send_data(stream.str());
}

std::shared_ptr<ICommand> makeStartCommand(TimeCounter& tc, networking::IServer& server, const std::vector<std::string>& args) {
    return std::make_shared<StartCommand>(tc, server, args);
}
