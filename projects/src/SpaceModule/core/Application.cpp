#include "Application.h"

namespace SpaceModule
{
	Application::Application() :
		s_UISystem(new UISystem()),
		s_InputSystem(new InputSystem())
	{
		s_InputSystem->LinkEventCaller(s_UISystem->GetEventCaller());
	}
	Application::~Application()
	{
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