cmake_minimum_required(VERSION 3.5.0)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
	cmake_policy(SET CMP0072 NEW)
endif(COMMAND cmake_policy)
project(BonesEngine VERSION 1.0.0)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/GLAD)
add_subdirectory(vendor/imgui)
add_subdirectory(vendor/GLM)

# Find source files
file(GLOB_RECURSE SOURCES src/*.cpp)
# Create shared library
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_precompile_headers(${PROJECT_NAME} PRIVATE src/bnspch.h)
target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_INCLUDE_NONE)
target_compile_definitions(${PROJECT_NAME} PUBLIC BNS_VERSION="${CMAKE_PROJECT_VERSION}")
if(WIN32)
	target_compile_definitions(${PROJECT_NAME} PUBLIC BNS_PLATFORM_WINDOWS)
	target_compile_definitions(${PROJECT_NAME} PUBLIC BNS_BUILD_DLL)
endif(WIN32)

if(UNIX)
	target_compile_definitions(${PROJECT_NAME} PUBLIC BNS_PLATFORM_LINUX)
endif(UNIX)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(${PROJECT_NAME} PUBLIC BNS_ENABLE_ASSERTS)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

# Include header files
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC src)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/spdlog/include)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/debugbreak/include)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/GLFW/include)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/imgui)
target_include_directories(${PROJECT_NAME} PUBLIC vendor/glm)


# Link
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} GLAD)
target_link_libraries(${PROJECT_NAME} imgui)
target_link_libraries(${PROJECT_NAME} glm)

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})