#include "JuceApplication.h"
#include "SpaceModule/s_ui_system/ui_elements/ui_Knob.h"

JuceApplication::JuceApplication() :
	Application(),
	s_JuceGraphicSystem(new JuceGraphicSystem())
{
	auto m_node_A = s_UISystem->PushNode(new SpaceModule::Nodes::ASDRNode());
	auto m_node_B = s_UISystem->PushNode(new SpaceModule::Nodes::ASDRNode());
	m_node_B->SetCustomName("VerticalNode");
	m_node_B->SetSizeAutoSnap(false);
	m_node_B->SetLayoutSnap(SpaceModule::XSnap::Right, SpaceModule::YSnap::Center);
	m_node_B->SetSize(50.0f,50.0f);
	m_node_B->GenerateTopRight();

	auto gainNode = s_UISystem->PushNode(new SpaceModule::Nodes::GainNode());
}

JuceApplication::~JuceApplication()
{
	delete s_JuceGraphicSystem;
}

void JuceApplication::Go(juce::Graphics& const g)
{
	s_JuceGraphicSystem->AppendJuceGraphics(g);
	s_UISystem->Go(*s_JuceGraphicSystem);
}

void JuceApplication::ProcessAudioSignal(float& in)
{
	s_UISystem->ProcessAudioSignal(in);
}
