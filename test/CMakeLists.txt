add_subdirectory(gtest)

add_executable(arg_parser-ut ArgParser-ut.cpp)
target_link_libraries(arg_parser-ut gtest_main tstat-lib)
add_test(NAME tstat_test COMMAND arg_parser-ut)
