#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_ui_system/UIElementRect.h"

namespace SpaceModule
{

	class UISystem
	{
	public:
		UISystem() = default;
		~UISystem();
	
		void PushElement(UIElement* element);
		void PushOverlay(UIElement* overlay);
		void PopElement(UIElement* element);
		void PopOverlay(UIElement* overlay);
	
	
	private: // node system core
		std::vector<UIElement*> m_Elements;
		unsigned int m_ElementInsertIndex = 0;
	};

};

