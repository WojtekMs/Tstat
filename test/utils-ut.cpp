#include "tstat/utils.hpp"

#include <gtest/gtest.h>
#include <thread>

TEST(UtilsTest, ParseArgsShouldReturnVectorOfArgumentsFromString)
{
    std::string input{"start dancing writing_essays drinking"};
    std::vector<std::string> expectedOutput{"start",
                                            "dancing",
                                            "writing_essays",
                                            "drinking"};
    EXPECT_EQ(expectedOutput, utils::parseArgs(input));
}

TEST(UtilsTest, ParseArgsShouldReturnEmptyVectorWhenEmptyString)
{
    std::string input{""};
    std::vector<std::string> expectedOutput{};
    EXPECT_EQ(expectedOutput, utils::parseArgs(input));
}

TEST(UtilsTest, JoinShouldTakeVariadicNumberOfArguments)
{
    std::string expectedOutput{"home/wojtek/networking/"};
    auto actualOutput = utils::join('/', "home", "wojtek", "networking");
    EXPECT_EQ(expectedOutput, actualOutput);
}

TEST(UtilsTest, GetElapsedTimeShouldReturnElapsedTime)
{
    std::string expectedOutput{"00:00:03"};
    auto start = std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    auto stop = std::chrono::system_clock::now();
    auto actualOutput = utils::getElapsedTime(stop, start);
    EXPECT_EQ(expectedOutput, actualOutput);
}
