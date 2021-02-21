cmake_minimum_required(VERSION 2.4.0)
project(GLAD)
# Find source files
file(GLOB_RECURSE SOURCES src/*.c)
# Create shared library
add_library(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Include header files
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})