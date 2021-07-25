#include "ui_Knob.h"

namespace SpaceModule
{
	namespace UI
	{
		Knob::Knob() :
			m_value(0.5f),
			m_radius(1.f),
			cmd_modifyValue(Input::CommandTemplate::ui_KnobModifyValue)
		{
			SetSize(vec2(40.0f, 40.0f));
			//SetLayoutDistance(vec2(100.0f, 100.0f));

			mouseBlock = true;
			mouseLeftButtonBlock = true; 
			SetValue(0.5f);

		}
		Knob::Knob(float size_in)
			: Knob()
		{
			SetSize(vec2(size_in, size_in));
		}
		Knob::~Knob()
		{
		}
		void Knob::OnRender(const GraphicSystem& s_g) const
		{
			s_g.DrawEllipse(layout.top_left_stack.x, layout.top_left_stack.y, size.x,size.y, 3.0f, m_color);
			vec2 center = layout.top_left_stack + size / 2.0f;
			vec2 end = rotate( vec2( 0.f, size.x * 0.5f ), m_knobAngle ) + center;
			s_g.DrawLine(center, end , 3.f, m_color);
		}
		void Knob::ModifyValueDrag()
		{
		}
		void Knob::ModifyValuePress()
		{
			pressed = true;
			//m_color = rgb(200, 100, 200);
			m_valuePreDrag = m_value;
		}
		void Knob::ModifyValueRelease()
		{
			pressed = false;
			//m_color = rgb(100, 200, 200);
		}

		void Knob::SetValue(float in)
		{
			m_value = in;
			m_value <= 1.f ? m_value >= 0.f ? m_value : m_value = 0.f : m_value = 1.f;

			m_knobAngle = angle( (degrees)( 360.0f * m_value ) );

			vec3 min_max_diff(m_color_max - m_color_min);
			vec3 color_change((1.f - m_value) * min_max_diff);
			m_color = rgb(m_color_min + color_change);
		}

		float Knob::GetValue() const
		{
			return m_value;
		}

		bool Knob::PressCall(InputInfoFinal<UIElement>& info_in){
			if (info_in.code == cmd_modifyValue.GetCode()){
				if (!HitTest(info_in.ms_x, info_in.ms_y)) 
					return false;

				if (info_in.type == Input::InputType::Press){
					info_in.wait_for_release = true;
					info_in.get_drag_info = true;
					info_in.object = this;
					cmd_modifyValue.y_preDrag = info_in.ms_y;
					ModifyValuePress();
					m_knobAnglePreDrag = m_knobAngle;
					return true;

				}	
			}
			return false;
		}

		void Knob::ReleaseCall(InputInfoFinal<UIElement>& info_in){
			if (info_in.code == cmd_modifyValue.GetCode()){
				ModifyValueRelease();
				info_in.get_drag_info = false;

				if (!HitTest(info_in.ms_x, info_in.ms_y)) {
				}
			}
		}

		void Knob::DragCall(const vec2& msPos_in)
		{
			float mod = cmd_modifyValue.y_preDrag - msPos_in.y ;
			SetValue(mod * 0.004f + m_valuePreDrag);
		}
	}
}