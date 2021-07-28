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
		void Knob::OnRenderMat4(const GraphicSystem& s_g, const mat4& mat_in) const
		{
			const bool isStrait = (float)mat_in[0][1] == 0.f;

			const float Mscale = (float)mat_in[2][2] * -1.f;

			if (isStrait) {
				const vec2 rect_tl = layout.top_left_stack * mat_in;

				const vec2 MSize = size * Mscale;

				s_g.DrawEllipse(rect_tl.x, rect_tl.y, MSize.x, MSize.y, 3.0f * Mscale, m_color);
				vec2 center = rect_tl + MSize / 2.0f;
				vec2 end = rotate(vec2(0.f, MSize.x * 0.5f), m_knobAngle) + center;
				s_g.DrawLine(center, end, 3.f * Mscale, m_color);
			} else {
				const vec2 center = layout.top_left_stack + size / 2.0f;
				const vec2 Mcenter = center * mat_in;
				const vec2 Mend = (rotate(vec2(0.f, size.x * 0.5f), m_knobAngle) + center) * mat_in;
				const vec2 MSize = size * Mscale;
				const vec2 top_left = (Mcenter - (MSize / 2.0f));
				s_g.DrawEllipse(top_left.x, top_left.y, MSize.x, MSize.y, 3.0f * Mscale, m_color);
				s_g.DrawLine(Mcenter, Mend, 3.f * Mscale, m_color);
			}
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

		bool Knob::PressCall(InputCall& call_in){
			if (cmd_modifyValue.PressInput(call_in)){
				if (!HitTest(call_in.GetMousePosition()))
					return false;
				cmd_modifyValue.y_preDrag = call_in.GetMousePosition().y;
				ModifyValuePress();
				m_knobAnglePreDrag = m_knobAngle;
				return true;
			}
			return false;
		}

		void Knob::ReleaseCall(InputCall&){
			ModifyValueRelease();
		}

		void Knob::DragCall(const vec2& msPos_in)
		{
			float mod = cmd_modifyValue.y_preDrag - msPos_in.y ;
			SetValue(mod * 0.004f + m_valuePreDrag);
		}
	}
}