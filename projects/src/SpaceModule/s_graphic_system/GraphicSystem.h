#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule
{
	
	class GraphicSystem
	{
	public:
		GraphicSystem();
		~GraphicSystem() = default;

	public: // virtual functions:
		virtual void DrawRect(const glm::vec2&, const glm::vec2&) const = 0;
		virtual void DrawRect(float a_x_in, float a_y_in, float b_x_in, float b_y_in) const = 0;
		virtual void DrawLine(const glm::vec2&, const glm::vec2&) const = 0;
		virtual void DrawImage() const = 0;

		//void DrawLayer();
	private:
		glm::vec<3, glm::u8, glm::qualifier::defaultp> color;
	};
	
}