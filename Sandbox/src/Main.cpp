#include <WitherEngine.h>

class ExampleLayer : public WitherEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		// WIT_INFO("ExampleLayer::Update");
	}

	void OnEvent(WitherEngine::Event &event) override
	{
		WIT_TRACE("{0}", event);
	}
};

class Sandbox : public WitherEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new WitherEngine::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

WitherEngine::Application *WitherEngine::CreateApplication()
{
	return new Sandbox();
}