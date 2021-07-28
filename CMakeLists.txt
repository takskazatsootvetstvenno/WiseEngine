cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME WiseEngine)
project(${PROJECT_NAME})

add_subdirectory(WiseEngineCore)
add_subdirectory(WiseEngineEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT WiseEngineEditor)
