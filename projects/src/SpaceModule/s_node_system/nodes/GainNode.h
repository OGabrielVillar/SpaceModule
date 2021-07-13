#pragma once

#include "SpaceModule/s_node_system/Node.h"
#include "SpaceModule/s_ui_system/ui_elements/ui_Knob.h"

namespace SpaceModule::Nodes
{

    class GainNode :
        public Node
    {
    public:
        GainNode();
        ~GainNode();

        virtual void OnAttach() override;
        //virtual void OnDetach() override;
        ////virtual void OnUpdate(Timestep ts) override {{}
        virtual void OnRender(const GraphicSystem& gs) override;
        ////virtual void OnEvent(Event & event) override {{}

        void ProcessAudioSignal(float& in) const;

    private:
        UI::Knob* m_gainKnob;
        UI::Knob* m_gainKnob2;
    };

}