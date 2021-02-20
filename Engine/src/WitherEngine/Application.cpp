#include <iostream>
#include "WitherEngine/Application.h"

#include "WitherEngine/Events/ApplicationEvent.h"
#include "WitherEngine/Log.h"
namespace WitherEngine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		WIT_TRACE(e);
		while (true)
			;
	}
}
