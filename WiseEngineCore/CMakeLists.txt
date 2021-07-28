cmake_minimum_required(VERSION 3.21)

set(ENGINE_PROJECT_NAME WiseEngineCore)

set(ENGINE_PUBLIC_INCLUDES
	includes/Application.hpp
	includes/Log.hpp
	includes/Event.hpp
)

set(ENGINE_PRIVATE_INCLUDES
	src/Window.hpp
)

set(ENGINE_PRIVATE_SOURCES
	src/Application.cpp
	src/Window.cpp
)

if(MSVC)
	 add_compile_options(/MP)
endif()

add_library(${ENGINE_PROJECT_NAME} STATIC
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE src)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

#glfw
add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

#glew
add_definitions(-DGLEW_STATIC)
option(glew-cmake_BUILD_SHARED off FORCE)
add_subdirectory(../external/glew ${CMAKE_CURRENT_BINARY_DIR}/glew)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE libglew_static)

#glm
add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glm)