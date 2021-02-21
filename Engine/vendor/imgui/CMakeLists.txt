project(imgui)
set(imgui_dir ${CMAKE_CURRENT_LIST_DIR}/imgui)
add_library(${PROJECT_NAME}
		${imgui_dir}/imgui_demo.cpp
		${imgui_dir}/imgui_draw.cpp
		${imgui_dir}/imgui_internal.h
		${imgui_dir}/imgui_widgets.cpp
		${imgui_dir}/imgui.cpp
		${imgui_dir}/imgui.h
		)
set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(${PROJECT_NAME} PUBLIC ${imgui_dir})