#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "Node.h"

namespace SpaceModule
{

	struct Camera {

	};

	class NodeSystem
	{
	public:
		NodeSystem() = default;
		~NodeSystem();

		void PushNode(Node* node);
		void PushOverlay(Node* overlay);
		void PopNode(Node* node);
		void PopOverlay(Node* overlay);


	private: // node system core
		Camera camera;
		std::vector<Node*> m_Nodes;
		unsigned int m_NodeInsertIndex = 0;
	};

}