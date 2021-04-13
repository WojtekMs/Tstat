#include "tstat/ShowCommand.hpp"

ShowCommand::ShowCommand(TimeCounter& tc, networking::IServer& server)
: counter_(tc), server_(server) {

}

void ShowCommand::execute() {
    server_.send_data(counter_.get_current_state_info());
}

std::shared_ptr<ICommand> makeShowCommand(TimeCounter& tc, networking::IServer& server, const std::string&) {
    return std::make_shared<ShowCommand>(tc, server);
}
