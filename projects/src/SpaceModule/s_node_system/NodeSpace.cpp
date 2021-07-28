#include "NodeSpace.h"

#include "SpaceModule/math/collision.h"

namespace SpaceModule
{
	NodeSpace::NodeSpace()
		: m_camera(-1.f,1.f,-1.f,1.f)
	{
		SetSizeAutoSnap(true);
		mat4Parent = true;
	}
	void NodeSpace::OnRender(const GraphicSystem& g) const
	{
		selectionBox.OnRender(g);
	}
	void NodeSpace::OnResize()
	{
		m_camera.SetScreenCenter(size / 2.f);
	}
	bool NodeSpace::PressCall(InputCall& call_in)
	{
	 //SELECTION BOX - [ON PRESS]
		if (selectionBox.OnPress(call_in))
			return true;
	 //CAMERA DRAG - [ON PRESS]
		if (cmd_CameraDragMovement.PressInput(call_in))
		{
			if ( !HitTest( call_in.GetMousePosition() ) )
				return false;

			m_camera.DragBegin( call_in.GetMousePosition());
			return true;
		}
	 //CAMERA ZOOM - [ON PRESS]
		if (cmd_CameraZoomIn.PressInput(call_in))
		{
			if ( !HitTest( call_in.GetMousePosition() ) )
				return false;

			m_camera.ScaleBy(1.1f);
			return true;
		}
		if (cmd_CameraZoomOut.PressInput(call_in))
		{
			if ( !HitTest( call_in.GetMousePosition() ) )
				return false;

			m_camera.ScaleBy(0.9f);
			return true;
		}
	 //CAMERA ROLL - [ON PRESS]
		if (cmd_CameraRollRight.PressInput(call_in))
		{
			if ( !HitTest( call_in.GetMousePosition() ) )
				return false;

			m_camera.RotateBy(angle(degrees(-10.f)));
			return true;
		}
		if (cmd_CameraRollLeft.PressInput(call_in))
		{
			if ( !HitTest(call_in.GetMousePosition() ) )
				return false;

			m_camera.RotateBy(angle(degrees(10.f)));
			return true;
		}
		return false;
	}
	void NodeSpace::ReleaseCall(InputCall& call_in)
	{
	 //SELECTION BOX - [ON RELEASE]
		if (selectionBox.OnRelease(call_in)) {
			return;
		}
	 //CAMERA DRAG - [ON RELEASE]
		if (cmd_CameraDragMovement.ReleaseInput(call_in)) {

			return;
		}
	}
	void NodeSpace::DragCall(const vec2& msPos_in)
	{
	 //SELECTION BOX - [ON DRAG]
		if ( selectionBox.OnDrag(msPos_in) ) {
			for (UIElement* element : childs) {
				const vec2 nodeTL = element->GetTopLeftStack() * m_camera.GetViewProjectionMatrix();
				const vec2 nodeBR = ( element->GetTopLeftStack() + element->GetSize() ) * m_camera.GetViewProjectionMatrix();
				vec2 boxTL;
				vec2 boxBR;
				selectionBox.PassRect(boxTL, boxBR);
				if (HitTestRectRect(boxTL, boxBR, nodeTL, nodeBR)) {
					selectionBox.UseRedColor();
				}
				else {
					selectionBox.UseYellowColor();
				}
			}
		}
	 //CAMERA DRAG - [ON DRAG]
		if (cmd_CameraDragMovement.IsDragging())
			m_camera.DragUpdate(msPos_in);
	}
	const mat4& NodeSpace::getMat4() const
	{
		return m_camera.GetViewProjectionMatrix();
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