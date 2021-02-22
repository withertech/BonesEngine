#pragma once

#include <BonesEngine/Layer.h>
#include <BonesEngine/Events/Event.h>
#include <BonesEngine/Events/ApplicationEvent.h>
#include <BonesEngine/Events/MouseEvent.h>
#include <BonesEngine/Events/KeyEvent.h>

namespace BonesEngine
{
	class BNS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}