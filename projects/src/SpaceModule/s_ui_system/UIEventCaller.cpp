#include "UIEventCaller.h"

namespace SpaceModule {
	UIEventCaller::UIEventCaller(UIElement& screen_in) :
		screen(&screen_in)
	{
	}
	void UIEventCaller::InputEvent(const InputInfo& info_in)
	{
		if (info.wait_for_release)
		{
			if (info_in.code != info.code) return;
			if (info_in.type != Input::InputType::Release) return;
			info = info_in;
			info.object->ReleaseCall(info);
			info.wait_for_release = false;
			return;
		}
		handled = false;
		info = info_in;
		ScanChilds(screen);
		return;
	}

	void UIEventCaller::OnMouseMovement(const vec2& msPos_in)
	{
		if (info.get_drag_info)
		{
			info.object->DragCall(msPos_in);
		}
	}

	void UIEventCaller::ScanChilds(UIElement* element_in)
	{
		if (!element_in->HitTest(info.ms_x, info.ms_y))
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
			if (element_in->PressCall(info))
				handled = true;
		}
		return;
	}
}