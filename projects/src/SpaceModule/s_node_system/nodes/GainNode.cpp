#include "GainNode.h"

namespace SpaceModule::Nodes
{
    GainNode::GainNode()
        : Node(NodeType::Gain),
          m_gainKnob(new UI::Knob(knobs_size)),
          m_pitchKnob(new UI::Knob(knobs_size))
    {
        size.x = (float)knobs_amount * (knobs_size + knobs_spacing) + knobs_spacing;
        size.y = knobs_size + knobs_spacing * 3.f;

        int knob_count = 0;
        m_gainKnob->SetParent(this);
        m_gainKnob->OnAttach();
        m_gainKnob->SetLayoutDistance(vec2((knobs_size + knobs_spacing) * (float)knob_count + knobs_spacing, knobs_spacing * 2.f));
        m_gainKnob->SetValue(0.f);

        knob_count++;
        m_pitchKnob->SetParent(this);
        m_pitchKnob->OnAttach();
        m_pitchKnob->SetLayoutDistance(vec2((knobs_size + knobs_spacing) * (float)knob_count + knobs_spacing, knobs_spacing * 2.f));
        m_pitchKnob->SetValue( std::sqrtf( get_note_frequency(Notes::A,4) / 20000.f ) );
    }

    GainNode::~GainNode()
    {
    }

    void GainNode::OnAttach()
    {
        GenerateTopRight();
    }

    void GainNode::OnRender(const GraphicSystem& gs) const
    {
        //WINDOW
        gs.FillRect(layout.top_left_stack.x, layout.top_left_stack.y, size.x, size.y, lo_bg_color);
        gs.DrawRect(layout.top_left_stack.x, layout.top_left_stack.y, size.x, size.y, lo_outline_color);

        //LABELS//
        int knob_count = 0;
        gs.DrawString("Gain", 10.f,
            ( layout.top_left_stack.x + (knobs_size + knobs_spacing) * (float)knob_count ) + 15.f,
            layout.top_left_stack.y + (knobs_size + knobs_spacing) + 10.f,
            knobs_size, 4.f,
            rgb(160, 160, 160));

        knob_count++;
        gs.DrawString((hzLabel + " Hz").c_str(), 10.f,
            ( layout.top_left_stack.x + (knobs_size + knobs_spacing) * (float)knob_count) + 15.f,
            (layout.top_left_stack.y + (knobs_size + knobs_spacing)) + 10.f,
            knobs_size, 4.f,
            rgb(160, 160, 160));
        /**/

        gs.DrawString("Oscillator", 13.f, layout.top_left_stack.x + 3.f, layout.top_left_stack.y + 1.f, 
                      100.f, 15.f, lo_title_color);
        /**/
    }

    void GainNode::OnRenderMat4(const GraphicSystem& gs, const mat4& mat_in) const
    {
        const bool isStrait = (float)mat_in[0][1] == 0.f;

        const float Mscale = (float)mat_in[2][2] * -1.f;

        const vec2 rect_tl = layout.top_left_stack * mat_in;

        if (isStrait) {
            //WINDOW
            gs.FillRect(rect_tl.x, rect_tl.y, size.x * Mscale, size.y * Mscale, lo_bg_color);
            gs.DrawRect(rect_tl.x, rect_tl.y, size.x * Mscale, size.y * Mscale, lo_outline_color);

            //LABELS//
            int knob_count = 0;
            gs.DrawString("Gain", 10.f * Mscale,
                rect_tl.x + ( ( ( knobs_size + knobs_spacing ) * (float)knob_count ) + 15.f ) * Mscale,
                rect_tl.y + ( ( knobs_size + knobs_spacing ) + 10.f ) * Mscale,
                knobs_size * Mscale, 4.f * Mscale,
                lo_title_color);

            knob_count++;
            gs.DrawString((hzLabel + " Hz").c_str(), 10.f * Mscale,
                rect_tl.x + ( ( ( knobs_size + knobs_spacing ) * (float)knob_count ) + 15.f )  * Mscale,
                rect_tl.y + ( ( knobs_size + knobs_spacing ) + 10.f ) * Mscale,
                knobs_size * Mscale, 4.f * Mscale,
                lo_title_color);
            /**/
            //Title//

            gs.DrawString("Oscillator", 13.f * Mscale, rect_tl.x + 3.f * Mscale, rect_tl.y + 1.f * Mscale,
                100.f * Mscale, 15.f * Mscale, lo_title_color);

            /**/
        } else {
            //WINDOW
            const vec2 rect_tr = vec2(layout.top_left_stack.x + size.x, layout.top_left_stack.y) * mat_in;
            const vec2 rect_br = (layout.top_left_stack + size) * mat_in;
            const vec2 rect_bl = vec2(layout.top_left_stack.x, layout.top_left_stack.y + size.y) * mat_in;

            gs.DrawLine(rect_tl, rect_tr, Mscale, lo_outline_color);
            gs.DrawLine(rect_tr, rect_br, Mscale, lo_outline_color);
            gs.DrawLine(rect_br, rect_bl, Mscale, lo_outline_color);
            gs.DrawLine(rect_bl, rect_tl, Mscale, lo_outline_color);
        }
    }

    bool GainNode::PressCall(InputCall& info_in)
    {
        return DragNode_Press(info_in);
    }
    void GainNode::DragCall(const vec2& msPos_in)
    {
        DragNode_Drag(msPos_in);
    }
    void GainNode::ReleaseCall(InputCall& info_in)
    {
        DragNode_Release(info_in);
    }

    void GainNode::ProcessAudioSignal(audiobuffer& data_in)
    {
        for (int channel = 0; channel < 1; channel++)
        {
            float wavelength = m_pitchKnob->GetValue() * m_pitchKnob->GetValue() * 20000.f;
            
            hzLabel = std::to_string((int)wavelength);

            wavelength *= sample_time();

            for (int sample = 0; sample < data_in.samples; sample++)
            {
                float& data(data_in.ptrptr[channel][sample]);
                wave1.push(wavelength);
                data = wave1 * m_gainKnob->GetValue();
            }
        }
    }

}