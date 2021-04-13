add_library(
  tstat-lib
  src/TimeCounter.cpp
  src/ArgParser.cpp
  src/CommandLoader.cpp
  src/StartCommand.cpp
  src/StopCommand.cpp
  src/AbortCommand.cpp
  src/utils.cpp
  )

target_link_libraries(tstat-lib networking-lib)
target_include_directories(tstat-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

