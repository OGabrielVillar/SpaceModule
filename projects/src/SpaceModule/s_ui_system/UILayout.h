#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule
{
	
	enum class XSnap : uint8_t
	{
		None = 0, Left = 1, Center = 2, Right = 3, ParentX = 4, ParentXOposite = 5
	};
	enum class YSnap : uint8_t
	{
		None = 0, Top = 1, Center = 2, Botton = 3, ParentY = 4, ParentYOposite = 5
	};

	class UILayout
	{
	public:
		UILayout() = default;
		~UILayout() = default;
	public:
		//user
		XSnap x_snap = XSnap::Left;
		YSnap y_snap = YSnap::Top;
		glm::vec2 distance = { 0.f, 0.f };

		float x_crop_max;
		float y_crop_max;
		float x_crop_min;
		float y_crop_min;

		//autos
		glm::vec2 top_left = { 0.f, 0.f };
		glm::vec2 top_left_stack = { 0.f, 0.f };
	};
}
