#include "GainNode.h"

namespace SpaceModule::Nodes
{
    GainNode::GainNode()
        : Node(NodeType::Gain),
          m_gainKnob(new UI::Knob(100.f)),
          m_gainKnob2(new UI::Knob(100.f))
    {
        layout.distance.x = 0;
        layout.distance.y = 0;
        size.x = 260.0f;
        size.y = 140.0f;

        m_gainKnob->SetParent(this);
        m_gainKnob->OnAttach();
        m_gainKnob->SetLayoutDistance(vec2(20.f));

        m_gainKnob2->SetParent(this);
        m_gainKnob2->OnAttach();
        m_gainKnob2->SetLayoutDistance(vec2(140.f, 20.f));
    }

    GainNode::~GainNode()
    {
    }

    void GainNode::OnAttach()
    {
        GenerateTopRight();
    }

    void GainNode::OnRender(const GraphicSystem& gs)
    {
        gs.FillRect(layout.top_right_stack.x, layout.top_right_stack.y, size.x, size.y, rgb(50, 50, 50));
        gs.DrawRect(layout.top_right_stack.x, layout.top_right_stack.y, size.x, size.y, rgb(100, 100, 100));
    }

    void GainNode::ProcessAudioSignal(float& data_in) const
    {
        data_in *= m_gainKnob->GetValue();
        data_in *= m_gainKnob2->GetValue();
    }

}