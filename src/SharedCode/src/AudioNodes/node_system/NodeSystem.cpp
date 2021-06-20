#include "NodeSystem.h"

namespace AudioNodes
{
	NodeSystem::~NodeSystem()
	{
		for (Node* node : m_Nodes)
		{
			node->OnDetach();
			delete node;
		}
	}

	void NodeSystem::PushNode(Node* node)
	{
		m_Nodes.emplace(m_Nodes.begin() + m_NodeInsertIndex, node);
		m_NodeInsertIndex++;
	}

	void NodeSystem::PushOverlay(Node* overlay)
	{
		m_Nodes.emplace_back(overlay);
	}

	void NodeSystem::PopNode(Node* node)
	{
		auto it = std::find(m_Nodes.begin(), m_Nodes.begin() + m_NodeInsertIndex, node);
		if (it != m_Nodes.begin() + m_NodeInsertIndex)
		{
			node->OnDetach();
			m_Nodes.erase(it);
			m_NodeInsertIndex--;
		}
	}

	void NodeSystem::PopOverlay(Node* overlay)
	{
		auto it = std::find(m_Nodes.begin() + m_NodeInsertIndex, m_Nodes.end(), overlay);
		if (it != m_Nodes.end())
		{
			overlay->OnDetach();
			m_Nodes.erase(it);
		}
	}
}
