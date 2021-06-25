#pragma once

#include "SpaceModule/s_node_system/Node.h"

namespace SpaceModule
{

    class ASDRNode :
        public Node
    {
    public:
        ASDRNode();
        ~ASDRNode();

        virtual void OnAttach() override;
        //virtual void OnDetach() override;
		////virtual void OnUpdate(Timestep ts) override {{}
        virtual void OnRender(GraphicSystem& const gs) override;
		////virtual void OnEvent(Event & event) override {{}
    };

}