cmake_minimum_required(VERSION 2.4.0)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
	cmake_policy(SET CMP0072 NEW)
endif(COMMAND cmake_policy)
project(WitherEngine)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/GLAD)
add_subdirectory(vendor/imgui)

# Find source files
file(GLOB_RECURSE SOURCES src/*.cpp)
# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_precompile_headers(${PROJECT_NAME} PRIVATE src/witpch.h)
target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_INCLUDE_NONE)
if(WIN32)
	target_compile_definitions(${PROJECT_NAME} PUBLIC WIT_PLATFORM_WINDOWS)
	target_compile_definitions(${PROJECT_NAME} PUBLIC WIT_BUILD_DLL)
endif(WIN32)

if(UNIX)
	target_compile_definitions(${PROJECT_NAME} PUBLIC WIT_PLATFORM_LINUX)
endif(UNIX)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(${PROJECT_NAME} PUBLIC WIT_ENABLE_ASSERTS)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

# Include header files
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/spdlog/include)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/GLFW/include)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/imgui)


# Link
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} GLAD)
target_link_libraries(${PROJECT_NAME} imgui)

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})