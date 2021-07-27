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

	bool keyPressed(const juce::KeyPress& key, juce::Component*) override {
		using namespace SpaceModule;
		InputInfo info( (Input::InputCode)key.getKeyCode(), Input::InputType::Press, 0.0f, 0.0f , key.getModifiers().getRawFlags() );
		m_app.s_InputSystem->InputEvent(info);
		
		return true;
	}
private:
	int lx = 0;
	JuceApplication& m_app;
};