#include "AppComponent.h"

void AppComponent::mouseMove(const juce::MouseEvent& event)
{
	mouse_position.x = event.getScreenX();
	mouse_position.y = event.getScreenY();
}