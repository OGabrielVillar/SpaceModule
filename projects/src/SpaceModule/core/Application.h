#pragma once

#include "SpaceModule\core\SpaceModuleHeader.h"
#include "SpaceModule\s_node_system\NodeSystem.h"
#include "SpaceModule\s_node_system\nodes\ASDRNode.h"

namespace SpaceModule
{

	class Application
	{
	public:
		Application();
		~Application();

	private: // application core
		Scope<NodeSystem> s_NodeSystem;
	};

}