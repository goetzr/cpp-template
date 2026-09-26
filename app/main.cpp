#include <spdlog/spdlog.h>

#include "app/core.hpp"

int main(int argc, char** argv) {
  spdlog::info("Application started");

  if (process("Test input")) {
    spdlog::info("Input processed successfully");
  } else {
    spdlog::error("Failed to process input");
  }

  return 0;
}
