#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_graphic_system/GraphicSystem.h"

#include "SpaceModule/s_ui_system/UIElement.h"
#include "ui_elements/include_ui_elements.h"
#include "SpaceModule/s_ui_system/UIEventCaller.h"
#include "SpaceModule/s_ui_system/ui_elements/ui_Background.h"
#include "SpaceModule/s_node_system/NodeSpace.h"

namespace SpaceModule
{

	class UISystem
	{
	public:
		UISystem();
		~UISystem();
	
		void WhenResized(float x_in, float y_in);
		UIElement* PushElement(UIElement* element_in);
		Node* PushNode(Node* node_in);
	
		void Render(const GraphicSystem&);
		void ProcessAudioSignal(SpaceModule::audiobuffer& signal_in);
		void ScanRender(UIElement*, const GraphicSystem&) const;

		UIEventCaller& GetEventCaller();
	private: // node system core
		UIEventCaller m_caller;

	private:	
		UI::Background screen;
		NodeSpace nodeSpace;
	};

};

