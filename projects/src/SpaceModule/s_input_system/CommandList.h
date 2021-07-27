#pragma once

namespace SpaceModule
{
	namespace Input
	{
		enum class CommandListContextType {
			None = 0,
			Empty,
			NodeEditorWindow,
			CustomContext
		};

		enum class CommandTemplate : unsigned int {
			None = 0,
			ui_ButtonPress = 100,
			ui_KnobModifyValue = 101,
			ui_PrintTimer = 102,
			ui_DragWindow = 103,
			ui_CameraDragMovement,
			ui_CameraZoomIn      ,
			ui_CameraZoomOut     ,
			ui_CameraRollCW      ,  //ClockWise
			ui_CameraRollCCW        //CounterClockWise
		};
	}
}

namespace SpaceModule
{
}