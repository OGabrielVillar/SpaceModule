#include "UIEventCaller.h"

namespace SpaceModule {
	UIEventCaller::UIEventCaller(UIElement& screen_in) :
		screen(&screen_in)
	{
	}
	void UIEventCaller::InputEvent(const InputInfo& info_in)
	{
		if ( m_call.Have( InputCall::Flag::WaitForRelease ) )
		{
			if ( m_call != info_in.code ) return;
			if ( info_in.type != Input::InputType::Release ) return;
			m_call = info_in;
			last_element->ReleaseCall(m_call);
			m_call.ClearFlags();

			return;
		}
		handled = false;
		m_call = info_in;
		ScanChilds(screen);

		return;
	}

	void UIEventCaller::OnMouseMovement(const vec2& msPos_in)
	{
		if ( m_call.Have( InputCall::Flag::GetDragCall ) )
		{
			last_element->DragCall(msPos_in);
		}
	}

	void UIEventCaller::ScanChilds(UIElement* element_in)
	{
		if (!element_in->HitTest(m_call.GetInfo().msPos))
			return;
		if (!element_in->GetChilds().empty()) {
			for (layerstack<UIElement*>::RevIterator element = element_in->GetChilds().rbegin();
			 element != element_in->GetChilds().rend(); element++){
				if (handled)
					return;
				ScanChilds(element.operator*());
			}
		}
		if (!handled) {
			if (element_in->PressCall(m_call))
				last_element = element_in;
				handled = true;
		}
		return;
	}
}