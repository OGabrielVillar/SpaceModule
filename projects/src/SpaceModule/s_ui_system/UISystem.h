#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_graphic_system/GraphicSystem.h"

#include "SpaceModule/s_ui_system/UIElement.h"
#include "ui_elements/include_ui_elements.h"
#include "SpaceModule/s_ui_system/UIEventCaller.h"

namespace SpaceModule
{

	class UISystem
	{
	public:
		UISystem();
		~UISystem();
	
		void WhenResized(float x_in, float y_in);
		UIElement* PushElement(UIElement* element);
		void PushOverlay(UIElement* overlay);
		void PopElement(UIElement* element);
		void PopOverlay(UIElement* overlay);
	
		void Go(const GraphicSystem&);
		void ScanChilds(UIElement*, const GraphicSystem&) const;

		UIEventCaller& GetEventCaller();
	private: // node system core
		std::vector<UIElement*> m_elements;
		unsigned int m_ElementInsertIndex = 0;
		UIEventCaller m_caller;
	public:	
		UIElement screen;
	};

};

