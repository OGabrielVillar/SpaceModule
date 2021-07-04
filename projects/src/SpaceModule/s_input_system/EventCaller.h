#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_input_system/Command.h"

namespace SpaceModule{

	class EventCaller
	{
	public:
		virtual void InputEvent(const InputInfo&) = 0;
		virtual void OnMouseMovement(const vec2&) = 0;
	};

}