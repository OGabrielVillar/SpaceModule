#pragma once

#include <JuceHeader.h>
#include "SpaceModule/core/Application.h"

class AppComponent : public juce::Component
{
public:
	AppComponent() = default;
	~AppComponent() = default;

	void mouseMove(const juce::MouseEvent& event) override;

	SpaceModule::Application app;
	glm::vec<2,int,glm::qualifier::defaultp> mouse_position;

private:

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AppComponent)
};

