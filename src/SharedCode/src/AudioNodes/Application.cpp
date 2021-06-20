#include "Application.h"

namespace AudioNodes
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