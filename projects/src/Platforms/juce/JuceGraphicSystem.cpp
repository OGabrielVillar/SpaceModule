#include "JuceGraphicSystem.h"

JuceGraphicSystem::JuceGraphicSystem() :
	GraphicSystem()
{
	;
}

void JuceGraphicSystem::DrawRect(const glm::vec2& pos_in, const glm::vec2& size_in) const
{
	g->drawRect((int)pos_in.x, (int)pos_in.y, (int)size_in.x, (int)size_in.y);
}

void JuceGraphicSystem::DrawLine(const glm::vec2&, const glm::vec2&) const
{
}

void JuceGraphicSystem::DrawImage() const
{
}

void JuceGraphicSystem::AppendJuceGraphics(juce::Graphics& const g_in)
{
	g = &g_in;
}
