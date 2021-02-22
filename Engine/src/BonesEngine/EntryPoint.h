#pragma once
extern BonesEngine::Application *BonesEngine::CreateApplication();
int main()
{
	BonesEngine::Log::Init();
	BNS_CORE_INFO("BonesEngine Version: {0}", BNS_VERSION);
	auto app = BonesEngine::CreateApplication();
	app->Run();
	delete app;
}