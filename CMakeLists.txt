cmake_minimum_required (VERSION 3.5.0)
if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)
project (Root VERSION 1.0.0)

add_subdirectory (Engine)
add_subdirectory (Sandbox)
