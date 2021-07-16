#include "GainNode.h"

namespace SpaceModule::Nodes
{
    GainNode::GainNode()
        : Node(NodeType::Gain),
          cmd_dragWindow(Input::CommandTemplate::ui_DragWindow),
          m_gainKnob(new UI::Knob(knobs_size)),
          m_distKnob(new UI::Knob(knobs_size)),
          m_randomKnob(new UI::Knob(knobs_size)),
          m_pitchKnob(new UI::Knob(knobs_size))
    {
        size.x = (float)knobs_amount * (knobs_size + knobs_spacing) + knobs_spacing;
        size.y = knobs_size + knobs_spacing * 3.f;

        knob_count = 0;
        m_gainKnob->SetParent(this);
        m_gainKnob->OnAttach();
        m_gainKnob->SetLayoutDistance(vec2((knobs_size + knobs_spacing) * (float)knob_count + knobs_spacing, knobs_spacing * 2.f));
        m_gainKnob->SetValue(0.f);

        knob_count++;
        m_distKnob->SetParent(this);
        m_distKnob->OnAttach();
        m_distKnob->SetLayoutDistance(vec2((knobs_size + knobs_spacing) * (float)knob_count + knobs_spacing, knobs_spacing * 2.f));

        knob_count++;
        m_randomKnob->SetParent(this);
        m_randomKnob->OnAttach();
        m_randomKnob->SetLayoutDistance(vec2((knobs_size + knobs_spacing) * (float)knob_count + knobs_spacing, knobs_spacing * 2.f));

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

    void GainNode::OnRender(const GraphicSystem& gs)
    {
        //WINDOW
        gs.FillRect(layout.top_right_stack.x, layout.top_right_stack.y, size.x, size.y, bg_color);
        gs.DrawRect(layout.top_right_stack.x, layout.top_right_stack.y, size.x, size.y, outline_color);

        //LABELS
        /*///////
        knob_count = 0;
        gs.DrawString("Gain", 10,          
            layout.top_right_stack.x + (knobs_size + knobs_spacing) * (float)knob_count, layout.top_right_stack.y + (knobs_size + knobs_spacing),
            knobs_size, 10.f, rgb(200, 200, 200));

        knob_count++;
        gs.DrawString("Drive", 10,         
            layout.top_right_stack.x + (knobs_size + knobs_spacing) * (float)knob_count, layout.top_right_stack.y + (knobs_size + knobs_spacing),
            knobs_size, 10.f, rgb(200, 200, 200));

        knob_count++;
        gs.DrawString("Random", 10,        
            layout.top_right_stack.x + (knobs_size + knobs_spacing) * (float)knob_count, layout.top_right_stack.y + (knobs_size + knobs_spacing),
            knobs_size, 10.f, rgb(200, 200, 200));

        knob_count++;
        gs.DrawString(hzLabel.c_str(), 10, 
            layout.top_right_stack.x + (knobs_size + knobs_spacing) * (float)knob_count, layout.top_right_stack.y + (knobs_size + knobs_spacing),
            knobs_size, 10.f, rgb(200, 200, 200));
        /**/

        gs.DrawString("Oscillator", 5, layout.top_right_stack.x + 3.f, layout.top_right_stack.y + 1.f, 
                      100.f, 15.f, rgb(200, 200, 200));
        /**/
    }

    bool GainNode::CommandCall(InputInfoFinal<UIElement>& info_in)
    {
        if (info_in.code == cmd_dragWindow.GetCode()) {
            if (HitTest(info_in.ms_x,info_in.ms_y)) {
                info_in.wait_for_release = true;
                info_in.get_drag_info = true;
                info_in.object = this;
                cmd_dragWindow.x_preDrag = info_in.ms_x;
                cmd_dragWindow.y_preDrag = info_in.ms_y;
                dist_preDrag = layout.distance;
                return true;
            }
        }
        return false;
    }

    void GainNode::DragCall(const vec2& msPos_in)
    {
        vec2 slope = msPos_in - vec2(cmd_dragWindow.x_preDrag, cmd_dragWindow.y_preDrag);
        SetLayoutDistance(dist_preDrag + slope);
    }

    void GainNode::ReleaseCall(InputInfoFinal<UIElement>& info_in)
    {
        if (info_in.code == cmd_dragWindow.GetCode()) {
            info_in.get_drag_info = false;
        }
    }

    void GainNode::ProcessAudioSignal(audiobuffer& data_in)
    {


        for (int channel = 0; channel < 1; channel++)
        {

            //float blend = m_distKnob->GetValue();
            //float dist = (m_distKnob->GetValue() * 6.f) + 1.f;

            //float randomBlend = m_randomKnob->GetValue();

            float wavelength = m_pitchKnob->GetValue() * m_pitchKnob->GetValue() * 20000.f;

            //wavelength = wave1_freq;
            
            hzLabel = std::to_string((int)wavelength);

            wavelength *= sample_time();

            for (int sample = 0; sample < data_in.samples; sample++)
            {
                float& data(data_in.ptrptr[channel][sample]);
                //data = ((((2.f / glm::pi<float>()) * std::atan(data * dist)) * blend) + data * (1.f - blend)) * m_gainKnob->GetValue();
                wave1.push(wavelength);
                data = wave1 * m_gainKnob->GetValue();
            }
        }
    }

}