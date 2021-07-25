#pragma once

#include <JuceHeader.h>
#include "Platforms/juce/JuceApplication.h"

class KeyManager : public juce::KeyListener
{
public:
	KeyManager(JuceApplication& app_in)
		: m_app(app_in)
	{}
	~KeyManager() {}

	bool keyPressed(const juce::KeyPress& key, juce::Component* originatingComponent) override {
		//SpaceModule::InputInfo(SpaceModule::Input::InputCode::,)
		//m_app.s_InputSystem->InputEvent(;
		lx++;
		return false;
	}
private:
	int lx = 0;
	JuceApplication& m_app;
};