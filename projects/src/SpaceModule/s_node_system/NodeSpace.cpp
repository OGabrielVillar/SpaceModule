#include "NodeSpace.h"

namespace SpaceModule
{
	NodeSpace::NodeSpace()
	{
		SetXSizeAutoSnap(true);
		SetYSizeAutoSnap(true);
	}
	void NodeSpace::ProcessAudioSignal(float& data_in)
	{
		for (UIElement* element : childs)
		{
			Node* node = dynamic_cast<Node*>(element);
			if (*node == NodeType::Gain)
			{
				Nodes::GainNode* gainNode = dynamic_cast<Nodes::GainNode*>(node);
				gainNode->ProcessAudioSignal(data_in);
			}
		}
	}
}