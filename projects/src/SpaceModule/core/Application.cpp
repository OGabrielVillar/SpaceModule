#include "Application.h"

namespace SpaceModule
{
	Application::Application() :
		s_NodeSystem(new NodeSystem()),
		s_UISystem(new UISystem())
	{
	}
	Application::~Application()
	{
	}
	void Application::Go()
	{
		s_NodeSystem->Go(*s_GraphicSystem);
	}
	void Application::WhenResized(float x_in, float y_in)
	{
		s_UISystem->WhenResized(x_in, y_in);
	}
}