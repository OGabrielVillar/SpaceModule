#include "InputSystem.h"

namespace SpaceModule
{
	void EventCaller::InputEvent(const InputInfo&)
	{
	}
}
namespace SpaceModule
{
	void InputSystem::InputEvent(const InputInfo& info_in)
	{
		for (EventCaller* caller : m_callers)
		{
			caller->InputEvent(info_in);
		}
	}
	void InputSystem::OnMouseMovement(const vec2& msPos_in)
	{
		for (EventCaller* caller : m_callers)
		{
			caller->OnMouseMovement(msPos_in);
		}
	}

	void InputSystem::LinkEventCaller(EventCaller& caller_in)
	{
		m_callers.push_back(&caller_in);
	}

}