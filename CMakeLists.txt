cmake_minimum_required(VERSION 3.13)

project(tstat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(networking-lib src/utils.cpp src/Server.cpp src/Client.cpp)

include_directories(inc)

add_executable(server_app src/server_main.cpp)
add_executable(client_app src/client_main.cpp)
add_executable(${PROJECT_NAME}-daemon src/daemon_main.cpp)
add_executable(${PROJECT_NAME} src/tstat_main.cpp)

target_link_libraries(server_app networking-lib)
target_link_libraries(client_app networking-lib)
target_link_libraries(${PROJECT_NAME}-daemon networking-lib)
target_link_libraries(${PROJECT_NAME} networking-lib)

