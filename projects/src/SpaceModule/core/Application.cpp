#include "Application.h"

namespace SpaceModule
{
	Application::Application() :
		s_NodeSystem(new NodeSystem())
	{
		s_NodeSystem->PushNode(new ASDRNode());
	}
	Application::~Application()
	{
	}
}