#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_ui_system/UILayout.h"
#include "SpaceModule/s_graphic_system/GraphicSystem.h"
#include "SpaceModule/s_input_system/Command.h"

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
		virtual void OnRender(const GraphicSystem& s_g) {}
		//virtual void OnEvent(Event & event) {}

	//setters
		void SetCustomName(const std::string&);
		void SetLayoutSnap(XSnap x_snap_in, YSnap y_snap_in);
		void SetSize(float x, float y);
		void SetSize(const glm::vec2&);
		void SetLayoutDistance(const glm::vec2&);
		void SetParent(UIElement*);
		void SetSizeAutoSnap(bool);
		void SetXSizeAutoSnap(bool);
		void SetYSizeAutoSnap(bool);
	//getters
		glm::vec2 GetTopLeft() const;
		const std::string& GetName() const { return m_customName; }
		layerstack<UIElement*>& GetChilds();
	//input:
		virtual bool CommandCall(InputInfoFinal<UIElement>&) { return false; }
		virtual void ReleaseCall(InputInfoFinal<UIElement>&) {}
		virtual void DragCall(const vec2&) {}

	//function
		bool HitTest(float x_in, float y_in) const;
		bool HitTest(const vec2&) const;

	//autos
		void GenerateTopRight();
	private:
		void RearrangeChilds();
		void RearrangeChildTopRightStack();
		void XSizeAutoSnap();
		void YSizeAutoSnap();


	protected: //
		glm::vec2 size;
		UILayout layout;
		UIElement* parent;
		layerstack<UIElement*> childs;
		std::string m_customName;

		bool x_size_autosnap = false; ///Snaps to the opposite side of the parent
		bool y_size_autosnap = false; ///Snaps to the opposite side of the parent

		bool mouseBlock = false;
		bool mouseLeftButtonBlock = false;
		bool mouseRightButtonBlock = false;
		bool mouseMiddleButtonBlock = false;
	};

}