#include <memory>

#include <gtest/gtest.h>
#include <spdlog/sinks/null_sink.h>
#include <spdlog/spdlog.h>

int main(int argc, char** argv) {
  // Create the null sink.
  auto null_sink = std::make_shared<spdlog::sinks::null_sink_st>();

  // Create a new logger with the null sink and make it the default.
  auto null_logger =
      std::make_shared<spdlog::logger>("default_null", null_sink);
  spdlog::set_default_logger(null_logger);

  // Parse Google Test flags from the command line and strip them from argv.
  ::testing::InitGoogleTest(&argc, argv);

  // Run all tests and return 0 on success, or 1 on failure.
  return RUN_ALL_TESTS();
}
