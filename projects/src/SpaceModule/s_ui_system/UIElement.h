#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_ui_system/UILayout.h"
#include "SpaceModule/s_graphic_system/GraphicSystem.h"

namespace SpaceModule
{

	class UIElement
	{
	public:
		UIElement();
		UIElement(UIElement* parent);
		virtual ~UIElement() = default;
	
	public:
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float ft) {}
		virtual void OnRender(GraphicSystem& const s_g) {}
		//virtual void OnEvent(Event & event) {}

		void SetLayoutSnap(XSnap x_snap_in, YSnap y_snap_in);
		void SetSize(float x, float y);
		void SetSize(glm::vec2& const);
		void SetLayoutDistance(glm::vec2& const);
		void GenerateTopRight();
		void SetParent(UIElement*);

		glm::vec2 GetTopLeft() const;
		const std::string& GetName() const { return m_customName; }

	private:

	protected: // node user interface
		glm::vec2 size;
		UILayout layout;
		UIElement* parent;
		std::string m_customName;
	};

}