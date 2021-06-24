#include "ASDRNode.h"

namespace SpaceModule
{
    ASDRNode::ASDRNode()
        : Node(NodeType::ASDR)
    {
        position = glm::vec2(100.0f, 100.0f);
        size = glm::vec2(100.0f, 200.0f);
    }

    ASDRNode::~ASDRNode()
    {
    }

    void ASDRNode::OnRender(GraphicSystem& const gs)
    {

        gs.DrawRect(position,size);

    }
    
}