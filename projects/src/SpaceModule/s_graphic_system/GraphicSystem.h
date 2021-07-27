#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule
{
	
	class GraphicSystem
	{
	public:
		GraphicSystem() :
			color(255, 255, 255) {}
		~GraphicSystem() = default;

	public: // virtual functions:
		virtual void DrawRect(const glm::vec2&, const glm::vec2&, const rgb& color_in) const = 0;
		virtual void FillRect(const glm::vec2&, const glm::vec2&, const rgb& color_in) const = 0;
		virtual void DrawRect(float a_x_in, float a_y_in, float b_x_in, float b_y_in, const rgb& color_in) const = 0;
		virtual void FillRect(float a_x_in, float a_y_in, float b_x_in, float b_y_in, const rgb& color_in) const = 0;
		virtual void DrawLine(const glm::vec2&, const glm::vec2&, float lineThickness_in, const SpaceModule::rgb& color_in) const = 0;
		virtual void DrawImage() const = 0;
		virtual void DrawEllipse(float x, float y, float width, float height, float lineThickness, const rgb& color_in) const = 0;
		virtual void DrawString(const char* string_in, float fontsize_in, float x_in, float y_in, float sizex_in, float sizey_in, const SpaceModule::rgb& color_in) const = 0;

		//void DrawLayer();
	private:
		glm::vec<3, glm::u8, glm::qualifier::defaultp> color;
	};
	
}