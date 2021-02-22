#include <BonesEngine.h>
#include <imgui/imgui.h>
class ExampleLayer : public BonesEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (BonesEngine::Input::IsKeyPressed(BNS_KEY_TAB))
			BNS_TRACE("Tab key is pressed (poll)");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}

	void OnEvent(BonesEngine::Event &event) override
	{
		if (event.GetEventType() == BonesEngine::EventType::KeyPressed)
		{
			BonesEngine::KeyPressedEvent &e = (BonesEngine::KeyPressedEvent &)event;
			if (e.GetKeyCode() == BNS_KEY_TAB)
				BNS_TRACE("Tab key is pressed (event)");
			BNS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public BonesEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

BonesEngine::Application *BonesEngine::CreateApplication()
{
	return new Sandbox();
}

std::string BonesEngine::Log::GetName()
{
	return "SANDBOX";
}