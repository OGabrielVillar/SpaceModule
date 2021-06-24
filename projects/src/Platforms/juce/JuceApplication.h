#pragma once

#include "SpaceModule/core/Application.h"

#include "AppComponent.h"
#include "JuceGraphicSystem.h"

class JuceApplication : SpaceModule::Application
{
public:
	JuceApplication();
	~JuceApplication();

	void Go(juce::Graphics& const g);
public:
	JuceGraphicSystem* s_JuceGraphicSystem;
	AppComponent comp;
};