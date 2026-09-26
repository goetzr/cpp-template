#include <print>

#include <spdlog/spdlog.h>

int main(int argc, char** argv) {
  spdlog::info("Application started");
  std::println("Hello, world");

  return 0;
}
