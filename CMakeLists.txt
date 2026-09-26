cmake_minimum_required(VERSION 3.30)

project(
    Template
    VERSION 0.0.1
    DESCRIPTION "Project description goes here"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

execute_process(
    COMMAND
        ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)

find_package(spdlog REQUIRED)
find_package(GTest REQUIRED)

add_executable(Template src/main.cpp)

target_compile_features(Template PRIVATE cxx_std_23)
set_target_properties(Template PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(
    Template
    PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wnon-virtual-dtor
)

target_link_libraries(Template spdlog::spdlog)
target_link_libraries(Template gtest::gtest)

add_custom_command(
    TARGET Template
    POST_BUILD
    COMMAND ln
    ARGS
        -f -s $<TARGET_FILE:Template>
        ${CMAKE_SOURCE_DIR}/$<TARGET_FILE_NAME:Template>
    COMMENT "Create a symlink to the built binary in the workspace directory."
)
