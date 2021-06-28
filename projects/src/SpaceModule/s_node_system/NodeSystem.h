#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"
#include "SpaceModule/s_graphic_system/GraphicSystem.h"

#include "Node.h"
#include "nodes/ASDRNode.h"

namespace SpaceModule
{

	struct Camera {
		vec2 position = vec2(0.0f);
		float zoom = 1.0f;
	};

	class NodeSystem
	{
	public:
		NodeSystem();
		~NodeSystem();

		Node* PushNodeToWindow(Node* node);
		Node* PushNodeToNode(Node*,Node*);
		void PushOverlay(Node* overlay);
		void PopNode(Node* node);
		void PopOverlay(Node* overlay);

		void Go(GraphicSystem& const);


	private: // node system core
		Camera camera;
		std::vector<Node*> m_nodes;
		unsigned int m_NodeInsertIndex = 0;
	public:
		UIElement window;
	};

}