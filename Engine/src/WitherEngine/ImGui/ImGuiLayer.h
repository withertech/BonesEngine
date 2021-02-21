#pragma once

#include <WitherEngine/Layer.h>
#include <WitherEngine/Events/Event.h>
#include <WitherEngine/Events/ApplicationEvent.h>
#include <WitherEngine/Events/MouseEvent.h>
#include <WitherEngine/Events/KeyEvent.h>

namespace WitherEngine
{
	class WIT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event &event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e);
		bool OnMouseMovedEvent(MouseMovedEvent &e);
		bool OnMouseScrolledEvent(MouseScrolledEvent &e);
		bool OnKeyPressedEvent(KeyPressedEvent &e);
		bool OnKeyReleasedEvent(KeyReleasedEvent &e);
		bool OnKeyTypedEvent(KeyTypedEvent &e);
		bool OnWindowResizeEvent(WindowResizeEvent &e);

	private:
		float m_Time = 0.0f;
	};
}