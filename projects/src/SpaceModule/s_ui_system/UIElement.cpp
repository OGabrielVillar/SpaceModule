#include "UIElement.h"

namespace SpaceModule
{

	UIElement::UIElement() :
		layout(),
		parent(nullptr),
		childs(),
		size(0.f,0.f)
	{
	}

	UIElement::UIElement(UIElement* parent_in):
		layout(),
		parent(parent_in),
		childs(),
		size(0.f, 0.f)
	{
	}

	void UIElement::SetCustomName(const std::string& customName_in)
	{
		m_customName = customName_in;
	}

	void UIElement::SetLayoutSnap(XSnap x_snap_in, YSnap y_snap_in)
	{
		layout.x_snap = x_snap_in;
		layout.y_snap = y_snap_in;
	}

	void UIElement::SetSize(float x_in, float y_in)
	{

		if (!x_size_autosnap)
		{
			size.x = x_in;
		}else
		{
			XSizeAutoSnap();
		}

		if (!y_size_autosnap)
		{
			size.y = y_in;
		}else
		{
			YSizeAutoSnap();
		}

		if ( layout.x_snap != XSnap::Left || layout.y_snap != YSnap::Top)
		{
			GenerateTopRight();
		}

		if (!childs.empty())
		{
			RearrangeChilds();
		}

	}

	void UIElement::SetSize(glm::vec2& const size_in)
	{
		SetSize(size_in.x, size_in.y);
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
				break;
			case YSnap::Center:
				layout.top_right.y = layout.distance.y + (parent->size.y * 0.5f) - (size.y * 0.5f);
				break;
			case YSnap::Botton:
				layout.top_right.y = layout.distance.y + parent->size.y - size.y;
				break;
		}
		layout.top_right_stack = parent->layout.top_right + layout.top_right;
	}

	void UIElement::SetParent(UIElement* element_in)
	{
		parent = element_in;
		element_in->childs.push_back(this);
		GenerateTopRight();
	}

	void UIElement::SetSizeAutoSnap(bool b_in)
	{
		x_size_autosnap = b_in;  y_size_autosnap = b_in;
	}

	void UIElement::SetXSizeAutoSnap(bool b_in)
	{
		x_size_autosnap = b_in;
	}

	void UIElement::SetYSizeAutoSnap(bool b_in)
	{
		y_size_autosnap = b_in;
	}

	void UIElement::RearrangeChilds()
	{
		for (UIElement* child : childs)
		{
			if (child->x_size_autosnap)
			{
				child->XSizeAutoSnap();
			}
			if (child->y_size_autosnap)
			{
				child->YSizeAutoSnap();
			}
			child->GenerateTopRight();
			child->RearrangeChilds();
		}
	}

	void UIElement::RearrangeChildTopRightStack()
	{
		for (UIElement* child : childs)
		{
			child->layout.top_right_stack = layout.top_right + child->layout.top_right;
			child->RearrangeChildTopRightStack();
		}
	}

	void UIElement::XSizeAutoSnap()
	{
		size.x = parent->size.x - layout.distance.x;
	}

	void UIElement::YSizeAutoSnap()
	{
		size.y = parent->size.y - layout.distance.y;
	}

}