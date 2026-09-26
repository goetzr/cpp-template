add_library(core src/core.cpp)
add_library(app::core ALIAS core)

target_include_directories(
    core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

find_package(spdlog REQUIRED)
target_link_libraries(core spdlog::spdlog)
