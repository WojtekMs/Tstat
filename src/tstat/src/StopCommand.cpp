#include "tstat/StopCommand.hpp"

#include <sstream>

StopCommand::StopCommand(TimeCounter& tc, networking::IServer& server)
: counter_(tc), server_(server) {

}

void StopCommand::execute() {
    try {
        counter_.stop();
        counter_.save();
    }
    catch (std::logic_error& e) {
        server_.send_data(e.what());
        return;
    }
    std::stringstream stream{};
    stream << "Counter stopped!\n";
    stream << counter_.get_current_state_info() << '\n';
    stream << "Saved to file: " << counter_.get_file_path().second << '\n';
    server_.send_data(stream.str());    
}

std::shared_ptr<ICommand> makeStopCommand(TimeCounter& tc, networking::IServer& server, const std::string&) {
    return std::make_shared<StopCommand>(tc, server);
}
