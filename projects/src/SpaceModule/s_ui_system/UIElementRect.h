#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_ui_system/UIElement.h"

namespace SpaceModule
{

	class UIElementRect : public UIElement
	{
	public:
		UIElementRect();
		virtual ~UIElementRect() = default;

	protected:
		glm::vec2 size;             //botton right
	};

}