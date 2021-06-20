#pragma once

#include "AudioNodes\AudioNodesHeader.h"
#include "node_system\NodeSystem.h"
#include "node_system\nodes\ASDRNode.h"

namespace AudioNodes
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