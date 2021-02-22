#pragma once
#include <BonesEngine/Core.h>
#include <BonesEngine/Events/Event.h>
#include <BonesEngine/Events/ApplicationEvent.h>
#include <BonesEngine/Window.h>
#include <BonesEngine/LayerStack.h>
#include <BonesEngine/ImGui/ImGuiLayer.h>
namespace BonesEngine
{
	class Application
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
		ImGuiLayer *m_ImGuiLayer;

		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application *s_Instance;
	};

	Application *CreateApplication();
}
