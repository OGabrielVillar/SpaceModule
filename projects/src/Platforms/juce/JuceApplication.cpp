#include "JuceApplication.h"

JuceApplication::JuceApplication() :
	Application(),
	s_JuceGraphicSystem(new JuceGraphicSystem())
{
	s_UISystem->PushElement(new SpaceModule::ASDRNode());

}

JuceApplication::~JuceApplication()
{
	delete s_NodeSystem;
	delete s_GraphicSystem;
	delete s_JuceGraphicSystem;
}

void JuceApplication::Go(juce::Graphics& const g)
{
	s_JuceGraphicSystem->AppendJuceGraphics(g);
	s_NodeSystem->Go(*s_JuceGraphicSystem);
	s_UISystem->Go(*s_JuceGraphicSystem);
}
