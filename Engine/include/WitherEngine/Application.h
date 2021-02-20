#pragma once
#include "Events/Event.h"
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
