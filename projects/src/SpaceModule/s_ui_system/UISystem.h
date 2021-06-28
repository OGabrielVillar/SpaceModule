#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_ui_system/UIElementRect.h"
#include "SpaceModule/s_graphic_system/GraphicSystem.h"

namespace SpaceModule
{

	class UISystem
	{
	public:
		UISystem();
		~UISystem();
	
		void WhenResized(float x_in, float y_in);
		void PushElement(UIElement* element);
		void PushOverlay(UIElement* overlay);
		void PopElement(UIElement* element);
		void PopOverlay(UIElement* overlay);
	
		void Go(GraphicSystem& const);
	private: // node system core
		std::vector<UIElement*> m_elements;
		unsigned int m_ElementInsertIndex = 0;
	public:	
		UIElement screen;
	};

};

