# Tstat

Tstat is an application that is supposed to help you realize how you manage your time spent at the computer. By giving simple commands you can activate appropriate counters that will measure the amount of time you spend at a certain activity.  
This application is built upon Client / Server architecture, using networking lib (based on TCP/IP Sockets) created by myself. Networking library is appended to this repository as a git submodule. User is supposed to use this application by issuing commands to the client app (`tstat`) which is communicating with the server app (`tstat_daemon`). Server is running as a daemon in the background.  
Further development plans assume that the application will save the results in a small data base and will provide you with data visualization in order to discover yet unkown trends or realize what is the most time consuming activity, which may lead to task optimization.

## C++ Features & Technologies

To create this project I used:
- [std::chrono](https://en.cppreference.com/w/cpp/chrono) library
- [std::filesystem](https://en.cppreference.com/w/cpp/filesystem) library
- git submodules ([networking-lib](https://github.com/WojtekMs/Networking))
- [Command](https://refactoring.guru/design-patterns/command) & [State](https://refactoring.guru/design-patterns/state) design patterns
- [GTest](https://github.com/google/googletest), mocking
- [CMake](https://cmake.org/) build system
- [RAII](https://en.cppreference.com/w/cpp/language/raii) idiom
- [fold expressions](https://en.cppreference.com/w/cpp/language/fold) & template variadic functions
- custom exceptions & `std::exception`'s
- unistd & sys/socket libs



## Building

This application uses Client / Server architecture and is built upon unix sockets. Due to this fact, it is necessary to have unix libraries. This application is currently only supported on unix platforms. As this repository contains git submodule please make sure that you download also the networking lib dependency by calling:
- git clone --recurse-submodules \<url>  

or  
  
- git clone \<url>
- git submodule update --init

Before building the application please change the `log_save_path` defined in `src/tstat/tstat/config.hpp`. This variable defines the path where tstat will save collected data.

- `mkdir build`
- `cd build`
- `cmake ..`
- `make -j`
- `make install`
- `./tstat_daemon`
- `./tstat <command> <args>`

## Running
Use this application by running the client app called `tstat`. Issue the commands by passing CLI args to the client.
This application handles commands:
- start \<task name> (this command starts the clock associated with a certain task name given as argument)
- stop (this command stops the clock and saves the time elapsed to a directory called as task name given at start)
- abort (this command cancels time measuring)
- list (allows you to see what tasks (tables/directories) are already present in the database)
- show (this command displays current state of the counter)

Currently it is posible to remove folders created by this application by simple rm commands, so please be cautious when modifying data directory.

## TODO
- feature that indicates when a certain amount of time already elapsed 
  - for example: ring a bell when 1hr passed
- feature that allows to see graphical interpretation of data recorded
- feature that allows you to clear database

