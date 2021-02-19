cmake_minimum_required(VERSION 2.4.0)

project(Sandbox)

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(include)
include_directories(../Engine/include)

# Create shared library
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries (${PROJECT_NAME} WitherEngine)

# Install executable
install(TARGETS ${PROJECT_NAME} DESTINATION bin/${PROJECT_NAME})