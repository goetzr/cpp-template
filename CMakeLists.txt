cmake_minimum_required(VERSION 3.30)

project(
    <PROJECT-NAME>
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

add_executable(<PROJECT-NAME> src/main.cpp)

target_compile_features(<PROJECT-NAME> PRIVATE cxx_std_23)
set_target_properties(<PROJECT-NAME> PROPERTIES CXX_EXTENSIONS OFF)
target_compile_options(
    <PROJECT-NAME>
    PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wnon-virtual-dtor
)

target_link_libraries(<PROJECT-NAME> spdlog::spdlog)

add_custom_command(
    TARGET <PROJECT-NAME>
    POST_BUILD
    COMMAND ln
    ARGS
        -s $<TARGET_FILE:<PROJECT-NAME>>
        ${CMAKE_SOURCE_DIR}/$<TARGET_FILE_NAME:<PROJECT-NAME>
    COMMENT "Create a symlink to the built binary in the workspace directory."
)
