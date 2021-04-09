#include "StartCommand.hpp"

#include <sstream>

StartCommand::StartCommand(TimeCounter& time_counter, IServer& server, const std::string& task_name) :
  time_counter_(time_counter),
  server_(server),
  task_name_(task_name)
{
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

std::shared_ptr<ICommand> makeStartCommand(TimeCounter& tc, IServer& server, const std::string& task) {
    return std::make_shared<StartCommand>(tc, server, task);
}
