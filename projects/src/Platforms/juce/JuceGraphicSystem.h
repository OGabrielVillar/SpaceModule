#pragma once

#include <JuceHeader.h>
#include "SpaceModule/s_graphic_system/GraphicSystem.h"

class JuceGraphicSystem : public SpaceModule::GraphicSystem
{
public:
	JuceGraphicSystem();
	~JuceGraphicSystem() = default;

	virtual void DrawRect(const glm::vec2&, const glm::vec2&) const override;
	virtual void DrawRect(float a_x_in, float a_y_in, float b_x_in, float b_y_in) const override;
	virtual void DrawLine(const glm::vec2&, const glm::vec2&) const override;
	virtual void DrawImage() const override;

	void AppendJuceGraphics(juce::Graphics& const);
private:
	juce::Graphics* g;
};