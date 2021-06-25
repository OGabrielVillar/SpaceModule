#pragma once

#include "SystemsHeader.h"
#include "Platforms/juce/JuceGraphicSystem.h"

namespace SpaceModule
{

	class Application
	{
	public:
		Application();
		~Application();

		virtual void Go();
		void WhenResized(float x_in, float y_in);

	protected: // application core
		NodeSystem* s_NodeSystem = nullptr;
		GraphicSystem* s_GraphicSystem = nullptr;
		UISystem* s_UISystem = nullptr;
	};

}