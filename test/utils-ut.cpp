#include <gtest/gtest.h>

#include "tstat/utils.hpp"

TEST(UtilsTest, ParseArgsShouldReturnVectorOfArgumentsFromString) {
    std::string input{"start dancing writing_essays drinking"};
    std::vector<std::string> expectedOutput{"start", "dancing", "writing_essays", "drinking"};
    EXPECT_EQ(expectedOutput, utils::parseArgs(input));
}

TEST(UtilsTest, ParseArgsShouldReturnEmptyVectorWhenEmptyString) {
    std::string input{""};
    std::vector<std::string> expectedOutput{};
    EXPECT_EQ(expectedOutput, utils::parseArgs(input));
}
