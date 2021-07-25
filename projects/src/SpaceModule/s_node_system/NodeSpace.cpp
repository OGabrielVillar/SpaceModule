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
		gs.DrawLine(tl, tr, 3.f, color);
		gs.DrawLine(tr, br, 3.f, color);
		gs.DrawLine(br, bl, 3.f, color);
		gs.DrawLine(bl, tl, 3.f, color);
	}
	void NodeSpace::OnResize()
	{
		m_camera.SetScreenCenter(size / 2.f);
	}
	bool NodeSpace::PressCall(InputInfoFinal<UIElement>& info_in)
	{
		if (info_in.code == Input::InputCode::MS_MiddleButton && info_in.type == Input::InputType::Press)
		{
			if (!HitTest(info_in.ms_x, info_in.ms_y))
				return false;
			info_in.wait_for_release = true;
			info_in.get_drag_info = true;
			info_in.object = this;
			msPos_preDrag.x = info_in.ms_x;
			msPos_preDrag.y = info_in.ms_y;
			cameraPos_PreDrag = m_camera.GetPosition();
			return true;

		}
		if (info_in.code == Input::InputCode::MS_RightButton && info_in.type == Input::InputType::Press)
		{
			if (!HitTest(info_in.ms_x, info_in.ms_y))
				return false;
			m_camera.RotateBy(angle(degrees(10.f)));
			return true;

		}
		if (info_in.code == Input::InputCode::MS_LeftButton && info_in.type == Input::InputType::Press)
		{
			if (!HitTest(info_in.ms_x, info_in.ms_y))
				return false;
			m_camera.RotateBy(angle(degrees(-10.f)));
			return true;

		}
		return false;
	}
	void NodeSpace::ReleaseCall(InputInfoFinal<UIElement>& info_in)
	{
		if (info_in.code == Input::InputCode::MS_MiddleButton && info_in.type == Input::InputType::Release) {
			info_in.get_drag_info = false;
		}
	}
	void NodeSpace::DragCall(const vec2& msPos_in)
	{
		const vec2 ms = msPos_in * m_camera.GetInverseMatrix();
		const vec2 msPD = msPos_preDrag * m_camera.GetInverseMatrix();
		m_camera.SetPosition( cameraPos_PreDrag - (ms - msPD) );
	}
	void NodeSpace::ProcessAudioSignal(SpaceModule::audiobuffer& data_in)
	{
		for (UIElement* element : childs)
		{
			Node* node = dynamic_cast<Node*>(element);
			if (*node == NodeType::Gain)
			{
				Nodes::GainNode* gainNode = dynamic_cast<Nodes::GainNode*>(node);
				gainNode->ProcessAudioSignal(data_in);
			}
		}
	}
}