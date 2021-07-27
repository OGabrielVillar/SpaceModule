#include "Node.h"

namespace SpaceModule
{

    SpaceModule::Node::Node(NodeType nodetype_in) :
        m_type(nodetype_in),
        cmd_dragNode(Input::CommandTemplate::ui_DragWindow)
    {
    }

	bool Node::DragNode_Press(InputCall& call_in)
	{
        if (cmd_dragNode.PressInput(call_in)) {
            if (HitTest(call_in.GetInfo().msPos)) {
                msPos_preDrag = call_in.GetInfo().msPos;
                dist_preDrag = layout.distance;
                UpdateSlopeBounds();
                return true;
            }
        }
        return false;
    }
	void Node::DragNode_Release(InputCall&)
	{
	}
	void Node::DragNode_Drag(const vec2& msPos_in)
	{
        vec2 slope = msPos_in - msPos_preDrag;

        if (slope.x > slope_limit.right)
            slope.x = slope_limit.right;
        else if (slope.x < slope_limit.left)
            slope.x = slope_limit.left;

        if (slope.y > slope_limit.bot)
            slope.y = slope_limit.bot;
        else if (slope.y < slope_limit.top)
            slope.y = slope_limit.top;

        vec2 result = dist_preDrag + slope;
        SetLayoutDistance(result);
	}
    void Node::UpdateSlopeBounds()
    {
        vec2 TopLeftSlope = layout.top_left_stack;
        vec2 BotRightSlope = (layout.top_left_stack + size);
        const vec2& parentTopLeftStack = parent->GetLayout().top_left_stack;
        slope_limit.bot = (parentTopLeftStack.y + parent->GetSize().y - slope_limit.margin) - TopLeftSlope.y;
        slope_limit.right = (parentTopLeftStack.x + parent->GetSize().x - slope_limit.margin) - TopLeftSlope.x;
        slope_limit.top = (parentTopLeftStack.y + slope_limit.margin) - BotRightSlope.y;
        slope_limit.left = (parentTopLeftStack.x + slope_limit.margin) - BotRightSlope.x;
    }

}