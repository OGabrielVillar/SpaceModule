#pragma once

#include <memory>

#include "SpaceModule/math/Math.h"
#include "SpaceModule/utils/layerstack.h"

#define BIT(x) (1 << x)

namespace SpaceModule {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	using vec2   = glm::vec2;
	using vec3   = glm::vec3;
	using vec4   = glm::vec4;
	using u8vec3 = glm::u8vec3;
	using u8vec4 = glm::u8vec4;
	using rgb    = glm::u8vec3;
	using rgba   = glm::u8vec4;

	template<typename T>
	using layerstack = utl::layerstack<T>;
}