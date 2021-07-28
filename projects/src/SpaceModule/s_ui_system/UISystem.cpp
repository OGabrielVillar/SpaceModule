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

	void UISystem::ScanRender(UIElement* element_in, const GraphicSystem& gs) const
	{
		element_in->OnRender(gs);
		if (element_in->isMat4Parent()) {
			for (UIElement* element : element_in->GetChilds()) {
				const mat4& matrix = element_in->getMat4();
				element->OnRenderMat4(gs, matrix);
				ScanRenderMat4(element, gs, matrix);
			}
		} else {
			for (UIElement* element : element_in->GetChilds()) {
				element->OnRender(gs);
				ScanRender(element, gs);
			}
		}
	}

	void UISystem::ScanRenderMat4(UIElement* element_in, const GraphicSystem& gs, const mat4& mat_in) const
	{
		element_in->OnRenderMat4(gs, mat_in);
		for (UIElement* element : element_in->GetChilds())
		{
			element->OnRenderMat4(gs, mat_in);
			ScanRenderMat4(element, gs, mat_in);
		}
	}

	void UISystem::Render(const GraphicSystem& gs)
	{
		ScanRender(&screen, gs);
	}

	UIEventCaller& UISystem::GetEventCaller()
	{
		return m_caller;
	}

	void UISystem::ProcessAudioSignal(SpaceModule::audiobuffer& signal_in)
	{
		nodeSpace.ProcessAudioSignal(signal_in);
	}
}
