#include <format>

#include <spdlog/spdlog.h>

#include "app/core.hpp"

bool process(std::string_view s) {
  spdlog::info(std::format("Processing input: {}", s));
  return !s.empty();
}
