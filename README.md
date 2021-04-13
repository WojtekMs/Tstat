# Tstat

Tstat is an application that is supposed to help you realize how you manage your time spent at the computer. By giving simple commands you can activate appropriate counters that will measure the amount of time you spend at a certain activity.  
This application is built upon Client / Server architecture, using networking lib (based on TCP/IP Sockets) created by myself. Networking library is appended to this repository as a git submodule. User is supposed to use this application by issuing commands to the client app (`tstat`) which is communicating with the server app (`tstat_daemon`). Server is running as a daemon in the background.  
Further development plans assume that the application will save the results in a small data base and will provide you with data visualization in order to discover yet unkown trends or realize what is the most time consuming activity, which may lead to task optimization.

## Building

This application uses Client / Server architecture and is built upon unix sockets. Due to this fact, it is necessary to have unix libraries. This application is currently only supported on unix platforms. As this repository contains git submodule please make sure that you download also the networking lib dependency by calling:
- git clone --recurse-submodules \<url>  

or  
  
- git clone \<url>
- git submodule update --init

Before building the application please change the `log_save_path` defined in `src/tstat/config.hpp`. This variable defines the path where tstat will save collected data.

## Running
Use this application by running the client app called `tstat`. Issue the commands by passing CLI args to the client.
This application handles commands:
- start \<task name> (this command starts the clock associated with a certain task name given as argument)
- stop (this command stops the clock and saves the time elapsed to a directory called as task name given at start)
- abort (this command cancels time measuring)

Currently it is posible to remove folders created by this application by simple rm commands, so please be cautious when modifying data directory.

## TODO
- feature that indicates when a certain amount of time already elapsed 
  - for example: ring a bell when 1hr passed
- feature that allows you to see what tasks (tables/directories) are already present in the database
- feature that allows to see graphical interpretation of data recorded
- state command pattern that will help manage time counter
- argument validation should be implemented in the command objects not in the arg parser  
(arg parser should only make sure that user passed a valid command object)
- feature that allows you to peek at what is the current state of the server / tstat daemon
  - is it measuring time?
  - what task is currently being measured?
  - how much time elapsed since the beginning of the measuring?

