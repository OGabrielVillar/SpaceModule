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
			ui_KnobModifyValue = 101
		};
	}
}

namespace SpaceModule
{
}