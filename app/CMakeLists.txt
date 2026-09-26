add_executable(app main.cpp)

target_link_libraries(app PRIVATE app::core)

find_package(spdlog REQUIRED)
target_link_libraries(app spdlog::spdlog)

add_custom_command(
    TARGET app
    POST_BUILD
    COMMAND ln
    ARGS -f -s $<TARGET_FILE:app> ${CMAKE_SOURCE_DIR}/$<TARGET_FILE_NAME:app>
    COMMENT "Create a symlink to the application in the workspace directory."
)
