#pragma once

namespace WitherEngine
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application *CreateApplication();
}
