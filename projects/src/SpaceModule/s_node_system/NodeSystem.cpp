#include "NodeSystem.h"

namespace SpaceModule
{
	NodeSystem::NodeSystem() 
	{
		window.SetCustomName("NodeSystemWindow");
		window.SetSizeAutoSnap(true);
	}

	NodeSystem::~NodeSystem()
	{
		for (Node* node : m_nodes)
		{
			node->OnDetach();
			delete node;
		}
	}

	Node* NodeSystem::PushNodeToWindow(Node* node_in)
	{
		node_in->SetParent(&window);
		node_in->OnAttach();
		m_nodes.emplace(m_nodes.begin() + m_NodeInsertIndex, node_in);
		m_NodeInsertIndex++;
		return node_in;
	}

	Node* NodeSystem::PushNodeToNode(Node* node_in, Node* parent_in)
	{
		node_in->SetParent(parent_in);
		node_in->OnAttach();
		m_nodes.emplace(m_nodes.begin() + m_NodeInsertIndex, node_in);
		m_NodeInsertIndex++;
		return node_in;
	}

	void NodeSystem::PushOverlay(Node* overlay)
	{
		m_nodes.emplace_back(overlay);
	}

	void NodeSystem::PopNode(Node* node)
	{
		auto it = std::find(m_nodes.begin(), m_nodes.begin() + m_NodeInsertIndex, node);
		if (it != m_nodes.begin() + m_NodeInsertIndex)
		{
			node->OnDetach();
			m_nodes.erase(it);
			m_NodeInsertIndex--;
		}
	}

	void NodeSystem::PopOverlay(Node* overlay)
	{
		auto it = std::find(m_nodes.begin() + m_NodeInsertIndex, m_nodes.end(), overlay);
		if (it != m_nodes.end())
		{
			overlay->OnDetach();
			m_nodes.erase(it);
		}
	}
	void NodeSystem::Go(GraphicSystem& const gs)
	{
		for(Node* node : m_nodes)
		{
			node->OnRender(gs);
		}
	}
}
