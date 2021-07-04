#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"
#include "SpaceModule/s_ui_system/UIElement.h"
#include "SpaceModule/s_ui_system/UILayout.h"

namespace SpaceModule
{

	class UIField : public UIElement
	{
	public:
		UIField();
		~UIField();
	protected:
		std::vector<UIElement> m_elements;
	};

}