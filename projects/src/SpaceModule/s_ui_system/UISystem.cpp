#include "UISystem.h"

namespace SpaceModule
{
	UISystem::UISystem()
	{
		screen.SetCustomName("UISystemScreen");
	}
	UISystem::~UISystem()
	{
		for (UIElement* Element : m_elements)
		{
			Element->OnDetach();
			delete Element;
		}
	}

	void UISystem::WhenResized(float x_in, float y_in)
	{
		screen.SetSize(x_in, y_in);
		for (UIElement* Element : m_elements)
		{
			Element->GenerateTopRight();
		}
	}

	void UISystem::PushElement(UIElement* element_in)
	{
		element_in->SetParent(&screen);
		element_in->OnAttach();
		m_elements.emplace(m_elements.begin() + m_ElementInsertIndex, element_in);
		m_ElementInsertIndex++;
	}

	void UISystem::PushOverlay(UIElement* overlay)
	{
		m_elements.emplace_back(overlay);
		overlay->OnAttach();
	}

	void UISystem::PopElement(UIElement* Element)
	{
		auto it = std::find(m_elements.begin(), m_elements.begin() + m_ElementInsertIndex, Element);
		if (it != m_elements.begin() + m_ElementInsertIndex)
		{
			Element->OnDetach();
			m_elements.erase(it);
			m_ElementInsertIndex--;
		}
	}

	void UISystem::PopOverlay(UIElement* overlay)
	{
		auto it = std::find(m_elements.begin() + m_ElementInsertIndex, m_elements.end(), overlay);
		if (it != m_elements.end())
		{
			overlay->OnDetach();
			m_elements.erase(it);
		}
	}
	void UISystem::Go(GraphicSystem& const gs)
	{
		for (UIElement* Element : m_elements)
		{
			Element->OnRender(gs);
		}
	}
}
