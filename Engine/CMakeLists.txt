cmake_minimum_required(VERSION 2.4.0)

project(WitherEngine)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)
# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/GLFW)
find_package(OpenGL REQUIRED)

# Find source files
file(GLOB_RECURSE SOURCES src/*.cpp)
# Create shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_precompile_headers(${PROJECT_NAME} PRIVATE src/witpch.h)

if(WIN32)
	target_compile_definitions(${PROJECT_NAME} PUBLIC WIT_PLATFORM_WINDOWS)
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



# Link
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})