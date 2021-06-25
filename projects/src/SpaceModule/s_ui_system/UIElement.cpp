#include "UIElement.h"

namespace SpaceModule
{

	UIElement::UIElement() :
		layout()
	{
	}

	UIElement::UIElement(UIElement* parent_in):
		layout(),
		parent(parent_in)
	{
	}

	void UIElement::SetLayoutSnap(XSnap x_snap_in, YSnap y_snap_in)
	{
		//TODO ASSERT IF 0
		if ((char)x_snap_in > (char)2)
		{
			layout.snap_sign.x = -1.0f;
		}
		else
		{
			layout.snap_sign.x = 1.0f;
		}
		if ((char)y_snap_in > (char)2)
		{
			layout.snap_sign.y = -1.0f;
		}
		else
		{
			layout.snap_sign.y = 1.0f;
		}
		layout.x_snap = x_snap_in;
		layout.y_snap = y_snap_in;
	}

	void UIElement::SetSize(float x_in, float y_in)
	{
		size.x = x_in;
		size.y = y_in;
	}

	void UIElement::SetSize(glm::vec2& const size_in)
	{
		size = size_in;
	}

	void UIElement::SetLayoutDistance(glm::vec2& const dist_in)
	{
		layout.distance = dist_in;
	}

	glm::vec2 UIElement::GetTopLeft() const
	{
		return layout.top_right;
	}

	void UIElement::GenerateTopRight()
	{
		switch (layout.x_snap)
		{
			case XSnap::Left:
				layout.top_right.x = layout.distance.x;
				break;
			case XSnap::Center:
				layout.top_right.x = layout.distance.x + (parent->size.x * 0.5f) - (size.x * 0.5f);
				break;
			case XSnap::Right:
				layout.top_right.x = -layout.distance.x + parent->size.x - size.x;
				break;
				//TODO PARENT LOOK UP
		}
		switch (layout.y_snap)
		{
			case YSnap::Top:
				layout.top_right.y = layout.distance.y;
				return;
			case YSnap::Center:
				layout.top_right.y = layout.distance.y + (parent->size.y * 0.5f) - (size.y * 0.5f);
				return;
			case YSnap::Botton:
				layout.top_right.y = layout.distance.y + parent->size.y - size.y;
				return;
		}
	}

	void UIElement::SetParent(UIElement* element_in)
	{
		parent = element_in;
	}

}