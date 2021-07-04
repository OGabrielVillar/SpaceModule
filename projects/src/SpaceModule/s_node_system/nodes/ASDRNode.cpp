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
        SetYSizeAutoSnap(true);
        SetLayoutSnap(XSnap::Left, YSnap::Center);
    }

    ASDRNode::~ASDRNode()
    {
    }

    void ASDRNode::OnAttach()
    {
        GenerateTopRight();
    }

    void ASDRNode::OnRender(const GraphicSystem& gs)
    {
        gs.DrawRect( layout.top_right_stack.x, layout.top_right_stack.y, size.x, size.y , rgb(100, 100, 100));
    }
    
}