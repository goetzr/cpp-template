#include <string>

#include <gtest/gtest.h>

#include <app/core.hpp>

TEST(processTest, ReturnsTrueWhenInputNotEmpty) {
  std::string input("Test");
  EXPECT_TRUE(process(input)) << "Non-empty input should return true.";
}
