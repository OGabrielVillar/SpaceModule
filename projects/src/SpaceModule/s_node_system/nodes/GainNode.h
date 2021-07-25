#pragma once

#include "SpaceModule/s_node_system/Node.h"
#include "SpaceModule/s_ui_system/ui_elements/ui_Knob.h"
#include "SpaceModule/s_audio_system/audio.h"

namespace SpaceModule::Nodes
{

    class GainNode : public Node {
     public:
        GainNode();
        ~GainNode();

        virtual void OnAttach() override;
        //virtual void OnDetach() override;
        ////virtual void OnUpdate(Timestep ts) override {{}
        virtual void OnRender(const GraphicSystem& gs) const override;
        ////virtual void OnEvent(Event & event) override {{}

        virtual bool PressCall(InputInfoFinal<UIElement>&) override;
        virtual void DragCall(const vec2&) override;
        virtual void ReleaseCall(InputInfoFinal<UIElement>& info_in) override;


        void ProcessAudioSignal(audiobuffer& in);

     private:
        const int knobs_amount = 2;
        const float knobs_size = 50.f;
        const float knobs_spacing = 10.f;
        int knob_count = 1;

     private:
        UI::Knob* m_gainKnob;
        UI::Knob* m_pitchKnob;

     private:
        SineWave wave1;
        float wave1_freq = get_note_frequency(Notes::C, 4);
        string hzLabel;

     private:
         rgb lo_bg_color      = { 40, 40, 40 };
         rgb lo_outline_color = { 15, 15, 15 };
         rgb lo_title_color = { 180, 180, 180 };

    };

}