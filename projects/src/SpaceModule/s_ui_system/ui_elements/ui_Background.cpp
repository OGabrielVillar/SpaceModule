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
		bool Background::PressCall(InputCall& call_in)
		{
			if (cmd_printTimer.PressInput(call_in)) {
				m_clickPos = call_in.GetMousePosition();
				m_value = std::to_string(m_timer.update());
				return true;
			}
			return false;
		}
	}
}