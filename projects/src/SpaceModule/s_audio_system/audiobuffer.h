#pragma once

#include "SpaceModule/core/SpaceModuleHeader.h"


namespace SpaceModule {

	struct audiobuffer {
		audiobuffer() = delete;
		audiobuffer(float& buffer_in, int channels_in, int samples_in)
			: buffer(&buffer_in), ptrptr(&buffer), channels(channels_in), samples(samples_in)
		{}
	public:
		float* buffer;
		float** ptrptr;
		int channels;
		int samples;
	};
}