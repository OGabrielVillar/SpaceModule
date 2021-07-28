#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

#include "SpaceModule/s_ui_system/UILayout.h"
#include "SpaceModule/s_graphic_system/GraphicSystem.h"
#include "SpaceModule/s_input_system/Command.h"

namespace SpaceModule
{

	class UIElement
	{
	 protected:
		struct SlopeBounds {
			float margin = 10.f;
			float top = 0.0f;
			float left = 0.0f;
			float bot = 0.0f;
			float right = 0.0f;
		};

	 public:
		UIElement();
		UIElement(UIElement* parent);
		virtual ~UIElement() = default;
	
	 public:
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float) {}
		virtual void OnRender(const GraphicSystem&) const {}
		virtual void OnRenderMat4(const GraphicSystem&, const mat4&) const {}
		virtual void OnResize() {}
		//virtual void OnEvent(Event & event) {}

	 //input:
		virtual bool PressCall(InputCall&) { return false; }
		virtual void ReleaseCall(InputCall&) {}
		virtual void DragCall(const vec2&) {}

	 //setters
		void SetCustomName(const std::string&);
		void SetLayoutSnap(XSnap x_snap_in, YSnap y_snap_in);
		void SetSize(float x, float y);
		void SetSize(const vec2&);
		void SetLayoutDistance(const vec2&);
		void SetParent(UIElement*);
		void SetSizeAutoSnap(bool);
		void SetXSizeAutoSnap(bool);
		void SetYSizeAutoSnap(bool);
	 //getters
		vec2 GetTopLeft() const;
		const vec2& GetTopLeftStack() const { return layout.top_left_stack; }
		const string& GetName() const { return m_customName; }
		layerstack<UIElement*>& GetChilds();
		const UILayout& GetLayout() const { return layout; }
		const vec2& GetSize() const { return size; }
		virtual const mat4& getMat4() const { return mat4(); }
	 //is?
		bool isMat4Parent() const { return mat4Parent; }
	 //function
		bool HitTest(float x_in, float y_in) const;
		bool HitTest(const vec2&) const;

	 //autos
		void GenerateTopRight();
	 private:
		void RearrangeChilds();
		void RearrangeChildTopRightStack();
		void CheckAutoSnap();
		void XSizeAutoSnap();
		void YSizeAutoSnap();


	 protected: //members
		vec2 size;
		UILayout layout;
		UIElement* parent;
		layerstack<UIElement*> childs;
		string m_customName;

		bool x_size_autosnap = false; ///Snaps to the opposite side of the parent
		bool y_size_autosnap = false; ///Snaps to the opposite side of the parent

		bool mouseBlock = false;
		bool mouseLeftButtonBlock = false;
		bool mouseRightButtonBlock = false;
		bool mouseMiddleButtonBlock = false;
		bool mat4Parent = false;
	};

}