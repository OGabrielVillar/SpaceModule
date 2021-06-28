#include "Application.h"

namespace SpaceModule
{
	Application::Application() :
		s_NodeSystem(new NodeSystem()),
		s_UISystem(new UISystem())
	{
		s_NodeSystem->window.SetParent(&s_UISystem->screen);
	}
	Application::~Application()
	{
		delete s_NodeSystem;
		delete s_UISystem;
	}
	void Application::Go()
	{
	}
	void Application::WhenResized(float x_in, float y_in)
	{
		s_UISystem->WhenResized(x_in, y_in);
	}
}