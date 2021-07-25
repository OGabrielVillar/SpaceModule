#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_input_system/EventCaller.h"
#include "SpaceModule/s_ui_system/UIElement.h"

namespace SpaceModule {

	class UIEventCaller : public EventCaller
	{
	public:
		UIEventCaller(UIElement& screen_in);
		~UIEventCaller() = default;


		virtual void InputEvent(const InputInfo&) override;
		virtual void OnMouseMovement(const vec2&) override;


		void ScanChilds(UIElement*);


	private:
		UIElement* screen;
		InputCall m_call;
		UIElement* last_element;
		bool handled = false;
	};

}