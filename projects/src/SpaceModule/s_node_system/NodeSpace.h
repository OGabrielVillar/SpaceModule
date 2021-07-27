#pragma once

#include "nodes/include.h"
#include "SpaceModule/s_graphic_system/Cameras.h"

namespace SpaceModule
{
	class NodeSpace : public UIElement
	{
	public:
		NodeSpace();
		~NodeSpace() = default;

		virtual void OnRender(const GraphicSystem& gs) const override;
		virtual void OnResize() override;

		virtual bool PressCall(InputCall&) override;
		virtual void ReleaseCall(InputCall&) override;
		virtual void DragCall(const vec2&) override;

		void ProcessAudioSignal(SpaceModule::audiobuffer& in);

	private:
		vec2 rect_topLeft = { -1.f,-10.f }, rect_bottonRight = { 1.f, 50.f };

		vec2 msPos_preDrag = { 0.f , 0.f };
		vec2 cameraPos_PreDrag = { 0.f , 0.f };
		OrthographicCamera m_camera;

	private:
		Command cmd_CameraDragMovement = Input::CommandTemplate::ui_CameraDragMovement;
		Command cmd_CameraZoomIn = Input::CommandTemplate::ui_CameraZoomIn;
		Command cmd_CameraZoomOut = Input::CommandTemplate::ui_CameraZoomOut;
		Command cmd_CameraRollRight = Input::CommandTemplate::ui_CameraRollCW;
		Command cmd_CameraRollLeft = Input::CommandTemplate::ui_CameraRollCCW;
	};
}