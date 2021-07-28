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
		 
		 	virtual void OnRender(const GraphicSystem& s_g) const override;
			virtual void OnRenderMat4(const GraphicSystem& s_g, const mat4&) const override;
		 
		 	virtual bool PressCall(InputCall&) override;
		 	virtual void ReleaseCall(InputCall&) override;
		 	virtual void DragCall(const vec2&) override;
		 
		 	void ModifyValueDrag();
		 	void ModifyValuePress();
		 	void ModifyValueRelease();
		 
			void SetValue(float in);
		 	float GetValue() const;
		 private:
		 	bool pressed = false;
		 	float m_value;
		 	float m_valuePreDrag = 0.5f;
		 	float m_radius;
		 	Command cmd_modifyValue;
		 
		 	angle m_knobAngle = angle((degrees)180.f);
		 	angle m_knobAnglePreDrag = angle();
		 private:
			rgb m_color     = { 15, 15, 15 };
		    vec3 m_color_min = { 15.f, 15.f, 15.f };
		    vec3 m_color_max = { 30.f, 30.f, 30.f };
			float m_pressedColor = 0.8f;
		};

	}
}