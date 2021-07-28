#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_input_system/Command.h"
#include "SpaceModule/s_graphic_system/GraphicSystem.h"3
#include "SpaceModule/math/collision.h"

namespace SpaceModule {
	template<typename T>
	struct SelectionBox
	{
	 public:
		SelectionBox() = default;

		Command& cmd() { return m_cmd; }

		void OnRender(const GraphicSystem& g) const {
			if (m_cmd.IsDragging())
				g.DrawRect(m_boxTL, m_boxSize, m_color);
		}

		bool OnPress(InputCall& call_in)
		{
			if (m_cmd.PressInput(call_in))
			{
				m_msInitialPos = call_in.GetMousePosition();
				SelectionBoxOnDrag(m_msInitialPos);
				return true;
			}
			return false;
		}
		bool OnRelease(InputCall& call_in)
		{
			if (m_cmd.ReleaseInput(call_in)) {
				SelectionBoxOnDrag(call_in.GetMousePosition());
				return true;
			}
			return false;
		}
		bool OnDrag(const vec2& msPos_in)
		{
			if (m_cmd.IsDragging())
			{
				SelectionBoxOnDrag(msPos_in);
				return true;
			}
			return false;
		}

		void SelectionBoxOnDrag(const vec2& msPos_in)
		{
			m_msFinalPos = msPos_in;

			if (m_msInitialPos.x < m_msFinalPos.x) {
				m_boxTL.x = m_msInitialPos.x;
				m_boxBR.x = m_msFinalPos.x;
			}
			else {
				m_boxTL.x = m_msFinalPos.x;
				m_boxBR.x = m_msInitialPos.x;
			}
			if (m_msInitialPos.y < m_msFinalPos.y) {
				m_boxTL.y = m_msInitialPos.y;
				m_boxBR.y = m_msFinalPos.y;
			}
			else {
				m_boxTL.y = m_msFinalPos.y;
				m_boxBR.y = m_msInitialPos.y;
			}

			m_boxSize = m_boxBR - m_boxTL;
		}

		void PassRect(vec2& rectTL_out, vec2& rectBR_out) const {
			rectTL_out = m_boxTL;
			rectBR_out = m_boxBR;
		}
		void PassRect(vec2& rectTL_out, vec2& rectBR_out, vec2& rectSize_out) const {
			rectTL_out = m_boxTL;
			rectBR_out = m_boxBR;
			rectSize_out = m_boxSize;
		}

		void UseRedColor() { m_color = redColor; }
		void UseYellowColor() { m_color = yellowColor; }

	 private:
		rgb m_color = { 180,180,120 };
		const rgb yellowColor = { 180,180,120 };
		const rgb redColor = { 180,120,120 };
		layerstack<T> selection;
		bool selecting = false;
		Command m_cmd = Input::CommandTemplate::ui_SelectionBox;
		vec2 m_msInitialPos = { 0.0f, 0.0f };
		vec2 m_msFinalPos = { 0.0f, 0.0f };
		vec2 m_boxTL = { 0.0f, 0.0f }; //TopLeft
		vec2 m_boxBR = { 0.0f, 0.0f }; //BottonRight
		vec2 m_boxSize = { 0.0f, 0.0f };
	};

}