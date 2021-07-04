#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_input_system/Command.h"
#include "SpaceModule/s_input_system/EventCaller.h"

#include "SpaceModule/s_ui_system/UIEventCaller.h"

namespace SpaceModule
{

	class InputSystem
	{
	public:
		InputSystem() = default;
		~InputSystem() = default;

		void InputEvent(const InputInfo&);
		void OnMouseMovement(const vec2&);
		void LinkEventCaller(EventCaller&);
	private:
		std::vector<EventCaller*> m_callers;
	};

}