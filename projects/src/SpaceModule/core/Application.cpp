#include "Application.h"

namespace SpaceModule
{
	Application::Application() :
		s_NodeSystem(new NodeSystem())
	{
	}
	Application::~Application()
	{
	}
	void Application::Go()
	{
		s_NodeSystem->Go(*s_GraphicSystem);
	}
}