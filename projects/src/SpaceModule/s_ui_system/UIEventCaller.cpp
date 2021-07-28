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
			if (m_mat4) {
				last_element->DragCall(msPos_in * glm::inverse(*m_mat4));
			} else {
				last_element->DragCall(msPos_in);
			}
		}
	}

	void UIEventCaller::ScanChilds(UIElement* element_in)
	{
		if (!element_in->HitTest(m_call.GetMousePosition()))
			return;

		if (!element_in->GetChilds().empty()) {
			for (layerstack<UIElement*>::RevIterator element = element_in->GetChilds().rbegin();
			 element != element_in->GetChilds().rend(); element++){
				if (handled)
					return;
				if (!element_in->isMat4Parent()) {
					m_mat4 = nullptr;
					ScanChilds(element.operator*());
				} else {
					m_mat4 = &(element_in->getMat4());
					const vec2 offset = m_call.GetMousePosition() * glm::inverse(element_in->getMat4());
					ScanChildsMat4( element.operator*(), m_call.withOffset(offset) );
					m_call.stopOffset();
				}
			}
		}
		if (handled)
			return;

		m_mat4 = nullptr;
		if (element_in->PressCall(m_call)) {
			last_element = element_in;
			handled = true;
		}
	}

	void UIEventCaller::ScanChildsMat4(UIElement* element_in, InputCall& call_in)
	{
		if (!element_in->HitTest(call_in.GetMousePosition()))
			return;

		if (!element_in->GetChilds().empty()) {
			for (layerstack<UIElement*>::RevIterator element = element_in->GetChilds().rbegin();
				element != element_in->GetChilds().rend(); element++) {
				if (handled)
					return;
				ScanChildsMat4(element.operator*(), call_in);
			}
		}
		if (handled)
			return;

		if (element_in->PressCall(call_in)) {
			last_element = element_in;
			handled = true;
		}
	}

}