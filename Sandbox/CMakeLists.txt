cmake_minimum_required(VERSION 3.5.0)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)
project(Sandbox)

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(include)
include_directories(../Engine/include)
include_directories(../Engine/vendor/spdlog/include)
include_directories(../Engine/vendor/imgui/imgui)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries (${PROJECT_NAME} BonesEngine)

# Install executable
install(TARGETS ${PROJECT_NAME} DESTINATION bin/${PROJECT_NAME})