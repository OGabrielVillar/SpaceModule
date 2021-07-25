#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_ui_system/UIElement.h"
#include "SpaceModule/s_input_system/Command.h"

namespace SpaceModule
{
	namespace UI
	{

		class Background : public UIElement
		{
		public:
			Background();
			~Background();

			virtual void OnRender(const GraphicSystem& s_g) const override;
			virtual bool PressCall(InputInfoFinal<UIElement>&) override;

		private:
			rgb m_color = rgb(200,200,50);
			bool pressed = false;
		private:
			Command cmd_printTimer;
			string m_value;
			vec2 m_clickPos;
			utl::timer m_timer;
		};

	}
}