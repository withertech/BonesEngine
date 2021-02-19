#include <WitherEngine.h>

class Sandbox : public WitherEngine::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

WitherEngine::Application *WitherEngine::CreateApplication()
{
	return new Sandbox();
}