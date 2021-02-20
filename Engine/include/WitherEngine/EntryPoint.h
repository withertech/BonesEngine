#pragma once
extern WitherEngine::Application *WitherEngine::CreateApplication();
int main()
{
	WitherEngine::Log::Init();
	WIT_CORE_WARN("Initialized Logging");
	int a = 5;
	WIT_INFO("Hello! var={0}", a);
	auto app = WitherEngine::CreateApplication();
	app->Run();
	delete app;
}