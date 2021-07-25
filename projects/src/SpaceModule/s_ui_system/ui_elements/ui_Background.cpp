#include "ui_Background.h"

namespace SpaceModule
{
	namespace UI
	{
		Background::Background() :
			UIElement(),
			cmd_printTimer(Input::CommandTemplate::ui_PrintTimer),
			m_value(""),
			m_clickPos({ 0.0f,0.0f })
		{
		}
		Background::~Background()
		{
		}
		void Background::OnRender(const GraphicSystem& s_g) const
		{
			s_g.DrawString(m_value.c_str(),10,m_clickPos.x, m_clickPos.y, 100.f, 100.f, m_color);
		}
		bool Background::PressCall(InputInfoFinal<UIElement>& info_in)
		{
			if (info_in.code == cmd_printTimer.GetCode()) {
				if (info_in.type == Input::InputType::Press) {
					m_clickPos.x = info_in.ms_x;
					m_clickPos.y = info_in.ms_y;
					m_value = std::to_string(m_timer.update());
					return true;
				}
			}
			return false;
		}
	}
}