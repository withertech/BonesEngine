#pragma once
#include <WitherEngine/Core.h>
#include <WitherEngine/Events/Event.h>
#include <WitherEngine/Window.h>
namespace WitherEngine
{
	class WIT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application *CreateApplication();
}
