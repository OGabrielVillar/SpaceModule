#pragma once

#include "nodes/include.h"
#include "SpaceModule/s_graphic_system/Cameras.h"

#include "SpaceModule/s_ui_system/ui_tools/ui_SelectionBox.h"

namespace SpaceModule
{
	class NodeSpace : public UIElement
	{
	public:
		NodeSpace();
		~NodeSpace() = default;

		virtual void OnRender(const GraphicSystem&) const override;
		virtual void OnResize() override;

		virtual bool PressCall(InputCall&) override;
		virtual void ReleaseCall(InputCall&) override;
		virtual void DragCall(const vec2&) override;

		virtual const mat4& getMat4() const override;

		void ProcessAudioSignal(SpaceModule::audiobuffer& in);

	private:

	private:// Selection
		SelectionBox<Node> selectionBox;
	private:// Camera
		OrthographicCamera m_camera;

		vec2 msPos_preDrag = { 0.f , 0.f };
		vec2 cameraPos_PreDrag = { 0.f , 0.f };

		Command cmd_CameraDragMovement = Input::CommandTemplate::ui_CameraDragMovement;
		Command cmd_CameraZoomIn = Input::CommandTemplate::ui_CameraZoomIn;
		Command cmd_CameraZoomOut = Input::CommandTemplate::ui_CameraZoomOut;
		Command cmd_CameraRollRight = Input::CommandTemplate::ui_CameraRollCW;
		Command cmd_CameraRollLeft = Input::CommandTemplate::ui_CameraRollCCW;
	};
}