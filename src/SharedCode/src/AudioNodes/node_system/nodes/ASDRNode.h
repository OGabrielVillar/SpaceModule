#pragma once

#include "AudioNodes/node_system/Node.h"

namespace AudioNodes
{

    class ASDRNode :
        public Node
    {
    public:
        ASDRNode();
        ~ASDRNode();

        //virtual void OnAttach() override;
        //virtual void OnDetach() override;
		////virtual void OnUpdate(Timestep ts) override {{}
        //virtual void OnRender() override;
		////virtual void OnEvent(Event & event) override {{}
    };

}