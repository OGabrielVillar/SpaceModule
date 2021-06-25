#include "ASDRNode.h"

namespace SpaceModule
{
    ASDRNode::ASDRNode()
        : Node(NodeType::ASDR)
    {
        layout.distance.x = 0;
        layout.distance.y = 0;
        size.x = 100.0f;
        size.y = 10.0f;
        SetLayoutSnap(XSnap::Right, YSnap::Botton);
    }

    ASDRNode::~ASDRNode()
    {
    }

    void ASDRNode::OnAttach()
    {
        GenerateTopRight();
    }

    void ASDRNode::OnRender(GraphicSystem& const gs)
    {
        gs.DrawRect( layout.top_right.x, layout.top_right.y, size.x, size.y );

    }
    
}