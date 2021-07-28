#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"

namespace SpaceModule {

	inline bool HitTestRectRect(const vec2& aTL_in, const vec2& aBR_in, const vec2& bTL_in, const vec2& bBR_in) {


		if (aTL_in.x > bBR_in.x)
			return false;
		if (aBR_in.x < bTL_in.x)
			return false;
		if (aTL_in.y > bBR_in.y)
			return false;
		if (aBR_in.y < bTL_in.y)
			return false;

		return true;
	}

}



/* 
* 

	a.left < b.right
	a.right < b.right

	a.left > b.right
	a.right > b.right

	a.left < b.left
	a.right < b.left

	a.left > b.left
	a.right > b.left

	a.left < b.right
	a.right > b.right

	a.left > b.right
	a.right < b.right

	a.left < b.left
	a.right > b.left

	a.left > b.left
	a.right < b.left
	*/