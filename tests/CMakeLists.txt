add_executable(tests main.cpp core_tests.cpp)

find_package(spdlog REQUIRED)
find_package(GTest REQUIRED)
target_link_libraries(tests PRIVATE app::core spdlog::spdlog gtest::gtest)

include(GoogleTest)
gtest_discover_tests(tests)

add_custom_command(
    TARGET tests
    POST_BUILD
    COMMAND ln
    ARGS -f -s $<TARGET_FILE:tests> ${CMAKE_SOURCE_DIR}/trun
    COMMENT
        "Create a symlink to the test executable in the workspace directory."
)
