#include "NodeSpace.h"

namespace SpaceModule
{
	NodeSpace::NodeSpace()
		: m_camera(-1.f,1.f,-1.f,1.f)
	{
		SetSizeAutoSnap(true);
	}
	void NodeSpace::OnRender(const GraphicSystem& gs) const
	{
		const rgb color(255, 255, 255);
		const mat4& m = m_camera.GetViewProjectionMatrix();
		vec2 tl = rect_topLeft * m;
		vec2 br = rect_bottonRight * m;
		vec2 tr(rect_bottonRight.x , rect_topLeft.y);
		vec2 bl(rect_topLeft.x, rect_bottonRight.y);
		tr = tr * m;
		bl = bl * m;
		gs.DrawLine(tl, tr, 1.f, color);
		gs.DrawLine(tr, br, 1.f, color);
		gs.DrawLine(br, bl, 1.f, color);
		gs.DrawLine(bl, tl, 1.f, color);
	}
	void NodeSpace::OnResize()
	{
		m_camera.SetScreenCenter(size / 2.f);
	}
	bool NodeSpace::PressCall(InputCall& call_in)
	{
		if (call_in == Input::InputCode::MS_MiddleButton && call_in == Input::InputType::Press)
		{
			if (!HitTest(call_in.GetInfo().msPos))
				return false;
			call_in.SetFlag(InputCall::Flag::GetDragCall | InputCall::Flag::WaitForRelease);
			m_camera.DragBegin( call_in.GetInfo().msPos );
			return true;

		}
		if (call_in == Input::InputCode::MS_RightButton && call_in == Input::InputType::Press)
		{
			if (!HitTest(call_in.GetInfo().msPos))
				return false;
			//m_camera.RotateBy(angle(degrees(10.f)));
			m_camera.ScaleBy(1.1f);
			return true;

		}
		if (call_in == Input::InputCode::MS_LeftButton && call_in == Input::InputType::Press)
		{
			if (!HitTest(call_in.GetInfo().msPos))
				return false;
			//m_camera.RotateBy(angle(degrees(-10.f)));
			m_camera.ScaleBy(0.9f);
			return true;

		}
		return false;
	}
	void NodeSpace::ReleaseCall(InputCall& info_in)
	{
	}
	void NodeSpace::DragCall(const vec2& msPos_in)
	{
		m_camera.DragUpdate(msPos_in);
	}
	void NodeSpace::ProcessAudioSignal(SpaceModule::audiobuffer& data_in)
	{
		for (UIElement* element : childs)
		{
			Node* node = dynamic_cast<Node*>(element);
			if (node->GetNodeType() == NodeType::Gain)
			{
				Nodes::GainNode* gainNode = dynamic_cast<Nodes::GainNode*>(node);
				gainNode->ProcessAudioSignal(data_in);
			}
		}
	}
}