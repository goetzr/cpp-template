add_executable(tests core_tests.cpp)

target_link_libraries(tests PRIVATE app::core)

find_package(spdlog REQUIRED)
target_link_libraries(tests spdlog::spdlog)

find_package(GTest REQUIRED)
target_link_libraries(tests gtest::gtest)

include(GoogleTest)
gtest_discover_tests(tests)

add_custom_command(
    TARGET tests
    POST_BUILD
    COMMAND ln
    ARGS
        -f -s $<TARGET_FILE:tests> ${CMAKE_SOURCE_DIR}/$<TARGET_FILE_NAME:tests>
    COMMENT
        "Create a symlink to the test execeutable in the workspace directory."
)
