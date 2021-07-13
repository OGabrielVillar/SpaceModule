#include "UISystem.h"

namespace SpaceModule
{
	UISystem::UISystem() :
		m_caller(screen)
	{
		screen.SetCustomName("UISystemScreen");
		nodeSpace.SetParent(&screen);
		nodeSpace.OnAttach();
		nodeSpace.SetCustomName("NodeSpace");
	}
	UISystem::~UISystem()
	{
	}

	void UISystem::WhenResized(float x_in, float y_in)
	{
		screen.SetSize(x_in, y_in);
	}

	UIElement* UISystem::PushElement(UIElement* element_in)
	{
		element_in->SetParent(&screen);
		element_in->OnAttach();
		return element_in;
	}

	Node* UISystem::PushNode(Node* node_in)
	{
		node_in->SetParent(&nodeSpace);
		node_in->OnAttach();
		return node_in;
	}

	void UISystem::ScanChilds(UIElement* element_in, const GraphicSystem& gs) const
	{
		element_in->OnRender(gs);
		for (UIElement* element : element_in->GetChilds())
		{
			element->OnRender(gs);
			ScanChilds(element, gs);
		}
	}

	void UISystem::Go(const GraphicSystem& gs)
	{
		ScanChilds(&screen, gs);
	}

	UIEventCaller& UISystem::GetEventCaller()
	{
		return m_caller;
	}

	void UISystem::ProcessAudioSignal(float& signal_in)
	{
		nodeSpace.ProcessAudioSignal(signal_in);
	}
}
