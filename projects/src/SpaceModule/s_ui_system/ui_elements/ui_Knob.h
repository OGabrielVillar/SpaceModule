#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_ui_system/UIElement.h"
#include "SpaceModule/s_input_system/Command.h"

namespace SpaceModule
{
	namespace UI
	{

		class Knob : public UIElement
		{
		public:
			Knob();
			Knob(float size_in);
			~Knob();

			virtual void OnRender(const GraphicSystem& s_g) override;

			virtual bool CommandCall(InputInfoFinal<UIElement>&) override;
			virtual void ReleaseCall(InputInfoFinal<UIElement>&) override;
			virtual void DragCall(const vec2&) override;

			void ModifyValueDrag();
			void ModifyValuePress();
			void ModifyValueRelease();

			float GetValue() const;
		private:
			rgb m_color;
			bool pressed = false;
			float m_value;
			float m_valuePreDrag = 0.5f;
			float m_radius;
			Command cmd_modifyValue;

			angle m_knobAngle = angle((degrees)180.f);
			angle m_knobAnglePreDrag = angle();
		};

	}
}