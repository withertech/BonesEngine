#include <bnspch.h>
#include "LinuxInput.h"
#include <BonesEngine/Application.h>
#include <GLFW/glfw3.h>

namespace BonesEngine
{
#if defined(BNS_PLATFORM_LINUX)
	Input *Input::s_Instance = new LinuxInput();
#endif
	bool LinuxInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool LinuxInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}
	std::pair<float, float> LinuxInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return {(float)xpos, (float)ypos};
	}
	float LinuxInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}
	float LinuxInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}