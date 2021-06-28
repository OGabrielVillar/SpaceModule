#include "JuceApplication.h"

JuceApplication::JuceApplication() :
	Application(),
	s_JuceGraphicSystem(new JuceGraphicSystem())
{
	auto m_node_A = s_NodeSystem->PushNodeToWindow(new SpaceModule::ASDRNode());
	auto m_node_B = s_NodeSystem->PushNodeToNode(new SpaceModule::ASDRNode(), m_node_A);
	m_node_B->SetCustomName("VerticalNode");
	m_node_B->SetSizeAutoSnap(false);
	m_node_B->SetLayoutSnap(SpaceModule::XSnap::Right, SpaceModule::YSnap::Center);
	m_node_B->SetSize(50.0f,50.0f);
	m_node_B->GenerateTopRight();

}

JuceApplication::~JuceApplication()
{
	delete s_JuceGraphicSystem;
}

void JuceApplication::Go(juce::Graphics& const g)
{
	s_JuceGraphicSystem->AppendJuceGraphics(g);
	s_NodeSystem->Go(*s_JuceGraphicSystem);
	s_UISystem->Go(*s_JuceGraphicSystem);
}
