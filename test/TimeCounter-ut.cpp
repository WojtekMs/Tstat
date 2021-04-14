#include "tstat/TimeCounter.hpp"
#include "tstat/config.hpp"

#include <gtest/gtest.h>
#include <thread>

class TimeCounterTest : public ::testing::Test {
    protected:
    TimeCounter counter{};
};

TEST_F(TimeCounterTest, GetElapsedTimeShouldReturnElapsedTime)
{
    std::string expectedElapsedTime{"00:00:03"};
    counter.start("bob");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    counter.stop();
    EXPECT_EQ(expectedElapsedTime, counter.getElapsedTime());
}

TEST_F(TimeCounterTest, GetElapsedTimeShouldReturn_00_00_00_WhenIdle)
{
    std::string expectedElapsedTime{"00:00:00"};
    EXPECT_EQ(expectedElapsedTime, counter.getElapsedTime());
}
