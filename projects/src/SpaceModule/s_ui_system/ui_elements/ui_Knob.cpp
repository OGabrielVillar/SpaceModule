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
			SetSize(vec2(100.0f, 100.0f));
			//SetLayoutDistance(vec2(100.0f, 100.0f));

			mouseBlock = true;
			mouseLeftButtonBlock = true;

			m_color = rgb(200, 200, 100);
		}
		Knob::~Knob()
		{
		}
		void Knob::OnRender(const GraphicSystem& s_g)
		{
			s_g.DrawRect(layout.top_right_stack, size, m_color);
		}
		void Knob::ModifyValueDrag()
		{
		}
		void Knob::ModifyValuePress()
		{
			pressed = true;
			m_color = rgb(200, 100, 200);
			m_valuePreDrag = m_value;
		}
		void Knob::ModifyValueRelease()
		{
			pressed = false;
			m_color = rgb(100, 200, 200);
		}

		bool Knob::CommandCall(InputInfoFinal<UIElement>& info_in){
			if (info_in.code == cmd_modifyValue.GetCode()){
				if (!HitTest(info_in.ms_x, info_in.ms_y)) 
					return false;

				if (info_in.type == Input::InputType::Press){
					info_in.wait_for_release = true;
					info_in.get_drag_info = true;
					info_in.object = this;
					ModifyValuePress();
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
			float mod = msPos_in.x - cmd_modifyValue.x_preDrag;
			m_value = mod * 0.1f + m_valuePreDrag;
			if (m_value > 1.f)
			{
				m_value = 1.f;
			}
			else if (m_value < 0.f)
			{
				m_value = 0.f;
			}
			m_color.r = uint8_t(m_value * 255.f);
		}
	}
}