#pragma once

#include "SpaceModule/core/Application.h"

#include "JuceGraphicSystem.h"

class JuceApplication : public SpaceModule::Application
{
public:
	JuceApplication();
	~JuceApplication();

	void Render(juce::Graphics&);
	void ProcessAudioSignal(SpaceModule::audiobuffer&);
public:
	JuceGraphicSystem* s_JuceGraphicSystem;
	float* m_gain = nullptr;
};