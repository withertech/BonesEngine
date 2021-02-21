#pragma once
#include <WitherEngine/Core.h>
#include <WitherEngine/Events/Event.h>
#include <WitherEngine/Events/ApplicationEvent.h>
#include <WitherEngine/Window.h>
#include <WitherEngine/LayerStack.h>
namespace WitherEngine
{
	class WIT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event &e);

		void PushLayer(Layer *layer);
		void PushOverlay(Layer *layer);

		inline static Application &Get() { return *s_Instance; }
		inline Window &GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent &e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application *s_Instance;
	};

	Application *CreateApplication();
}
