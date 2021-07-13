#include "JuceGraphicSystem.h"

JuceGraphicSystem::JuceGraphicSystem() :
	GraphicSystem()
{
}

void JuceGraphicSystem::DrawRect(const glm::vec2& pos_in, const glm::vec2& size_in, const SpaceModule::rgb& color_in) const
{
	DrawRect((int)pos_in.x, (int)pos_in.y, (int)size_in.x, (int)size_in.y, color_in);
}

void JuceGraphicSystem::FillRect(const glm::vec2& pos_in, const glm::vec2& size_in, const SpaceModule::rgb& color_in) const
{
	FillRect((int)pos_in.x, (int)pos_in.y, (int)size_in.x, (int)size_in.y, color_in);
}

void JuceGraphicSystem::DrawRect( float a_x_in, float a_y_in, float b_x_in, float b_y_in , const SpaceModule::rgb& color_in) const
{
	g->setColour(juce::Colour(color_in.r, color_in.g, color_in.b));
	g->drawRect((int)a_x_in, (int)a_y_in, (int)b_x_in, (int)b_y_in);
}

void JuceGraphicSystem::FillRect(float a_x_in, float a_y_in, float b_x_in, float b_y_in, const SpaceModule::rgb& color_in) const
{
	g->setColour(juce::Colour(color_in.r, color_in.g, color_in.b));
	g->fillRect((int)a_x_in, (int)a_y_in, (int)b_x_in, (int)b_y_in);
}

void JuceGraphicSystem::DrawLine(const glm::vec2& a_in, const glm::vec2& b_in, float lineThickness_in, const SpaceModule::rgb& color_in) const
{
	g->setColour(juce::Colour(color_in.r, color_in.g, color_in.b));
	g->drawLine(a_in.x,a_in.y,b_in.x,b_in.y, lineThickness_in);
}

void JuceGraphicSystem::DrawImage() const
{
}

void JuceGraphicSystem::DrawEllipse(float x_in, float y_in, float width_in, float height_in, float lineThickness_in, const SpaceModule::rgb& color_in) const
{
	g->setColour(juce::Colour(color_in.r, color_in.g, color_in.b));
	g->drawEllipse(x_in,y_in,width_in,height_in,lineThickness_in);
}

void JuceGraphicSystem::DrawString(const char* string_in,int fontsize_in, float x_in, float y_in, float sizex_in, float sizey_in, const SpaceModule::rgb& color_in) const
{
	g->setColour(juce::Colour(color_in.r, color_in.g, color_in.b));
	g->drawText(juce::String(string_in), (int)x_in, (int)y_in, (int)sizex_in, (int)sizey_in, juce::Justification::topLeft);
}

void JuceGraphicSystem::AppendJuceGraphics(juce::Graphics& const g_in)
{
	g = &g_in;
	g->fillAll(juce::Colours::black);
}
