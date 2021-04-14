#include <gtest/gtest.h>

#include "tstat/TimeCounter.hpp"
#include "tstat/config.hpp"
#include <thread>

TEST(TimeCounterTest, GetElapsedTimeShouldReturnElapsedTime) {
    std::string expectedElapsedTime{"00:00:03"};
    TimeCounter counter{};
    counter.start("");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    counter.stop();
    EXPECT_EQ(expectedElapsedTime, counter.get_elapsed_time());
}
