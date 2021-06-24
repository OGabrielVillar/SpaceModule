#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"
#include "SpaceModule/s_graphic_system/GraphicSystem.h"

#include "Node.h"
#include "nodes/ASDRNode.h"

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

		void Go(GraphicSystem& const);


	private: // node system core
		Camera camera;
		std::vector<Node*> m_Nodes;
		unsigned int m_NodeInsertIndex = 0;
	};

}