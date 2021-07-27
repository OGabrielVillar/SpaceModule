#pragma once

#define USING_JUCE_API

#include <memory>

#include "SpaceModule/math/Math.h"
#include "SpaceModule/math/angle.h"
#include "SpaceModule/utils/layerstack.h"
#include "SpaceModule/utils/random.h"
#include "SpaceModule/utils/time.h"

#define BIT(x) (1 << x)

namespace SpaceModule {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	using string = std::string;

	template<typename T>
	using layerstack = utl::layerstack<T>;
}