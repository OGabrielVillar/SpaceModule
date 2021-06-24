#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule
{

	class UIElement
	{
	public:
		UIElement();
		virtual ~UIElement() = default;
	
	public:

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float ft) {}
		virtual void OnRender() {}
		//virtual void OnEvent(Event & event) {}

	protected: // node user interface
		glm::vec2 position;         //top left
		std::string m_CustomName;
	};

}