#pragma once

#include <JuceHeader.h>
#include "SpaceModule/s_graphic_system/GraphicSystem.h"

class JuceGraphicSystem : public SpaceModule::GraphicSystem
{
public:
	JuceGraphicSystem();
	~JuceGraphicSystem() = default;

	virtual void DrawRect(const glm::vec2&, const glm::vec2&, const SpaceModule::rgb& color_in) const override;
	virtual void FillRect(const glm::vec2&, const glm::vec2&, const SpaceModule::rgb& color_in) const override;
	virtual void DrawRect(float a_x_in, float a_y_in, float b_x_in, float b_y_in, const SpaceModule::rgb& color_in) const override;
	virtual void FillRect(float a_x_in, float a_y_in, float b_x_in, float b_y_in, const SpaceModule::rgb& color_in) const override;
	virtual void DrawLine(const glm::vec2&, const glm::vec2&, float lineThickness_in, const SpaceModule::rgb& color_in) const override;
	virtual void DrawImage() const override;
	virtual void DrawEllipse(float x, float y, float width, float height, float lineThickness, const SpaceModule::rgb& color_in) const override;
	virtual void DrawString(const char* string_in, int fontsize_in, float x_in, float y_in, float sizex_in, float sizey_in, const SpaceModule::rgb& color_in) const override;

	void AppendJuceGraphics(juce::Graphics& const);
private:
	juce::Graphics* g;
};