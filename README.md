# Tstat

Tstat is an application that is supposed to help you realize how you manage your time spent at the computer. By giving simple commands you can activate appropriate counters that will measure the amount of time you spent at a certain activity. This application will then save the results in a small data base, and will provide you with data visualization in order to discover yet unkown trends or realize what is the most time consuming activity, which may lead to task optimization.

## Building & running

This application uses Server / Client architecture and is built upon unix sockets. Due to this fact, it is necessary to have unix libraries. This application is currently only supported on unix platforms. After proceeding regular building procedure using cmake, please remember to set appropriate privilages to the application:
- super user id
- root permission

Setting those privilages will help you to avoid mistakes when digging into collected data. It is now impposible to remove folders created by this application if you are not a super user. It is possible to delete the folders created by this app only from inside the application, not by accident.
