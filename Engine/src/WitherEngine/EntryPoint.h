#pragma once
extern WitherEngine::Application *WitherEngine::CreateApplication();
int main()
{
	WitherEngine::Log::Init();
	auto app = WitherEngine::CreateApplication();
	app->Run();
	delete app;
}