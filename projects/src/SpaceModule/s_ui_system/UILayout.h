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
		UILayout();
		~UILayout();
	public:
		//user
		XSnap x_snap;
		YSnap y_snap;
		glm::vec2 distance;

		float x_crop_max;
		float y_crop_max;
		float x_crop_min;
		float y_crop_min;

		//auto
		glm::vec2 snap_sign; // 1.0f||-1.f

		glm::vec2 top_right;
	};

	struct UIFieldLayout
	{
		//user
		glm::vec2 size;
		XSnap x_snap;
		YSnap y_snap;
		glm::vec2 distance;

		//auto
		glm::vec2 snap_sign; // 1.0f||-1.f
	};
}
