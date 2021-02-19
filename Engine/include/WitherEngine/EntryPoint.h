#pragma once
extern WitherEngine::Application *WitherEngine::CreateApplication();

int main()
{
	auto app = WitherEngine::CreateApplication();
	app->Run();
	delete app;
}