# Tstat

Tstat is an application that is supposed to help you realize how you manage your time spent at the computer. By giving simple commands you can activate appropriate counters that will measure the amount of time you spent at a certain activity. This application will then save the results in a small data base, and will provide you with data visualization in order to discover yet unkown trends or realize what is the most time consuming activity, which may lead to task optimization.

## Building & running

This application uses Server / Client architecture and is built upon unix sockets. Due to this fact, it is necessary to have unix libraries. This application is currently only supported on unix platforms.  
As a temporary solution before RDBSM will be applied to this program I recommend setting elevated privilages to the application:
- super user id
- root permission

Setting those privilages will help you avoid mistakes when changing, looking into collected data.  
Currently it is posible to remove folders created by this application by simple rm commands.  
After setting above mentioned privileges folders created by the application will be protected by root privilages.

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


## Done
- abort command that allows you to stop counting and do not save to database

