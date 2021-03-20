cmake_minimum_required(VERSION 3.13)

project(time-daemon)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(networking-lib src/utils.cpp src/Server.cpp src/Client.cpp)

include_directories(inc)

add_executable(server_app src/server_main.cpp src/Server.cpp src/utils.cpp)
add_executable(client_app src/client_main.cpp src/Client.cpp src/utils.cpp)
add_executable(${PROJECT_NAME} src/main.cpp)

