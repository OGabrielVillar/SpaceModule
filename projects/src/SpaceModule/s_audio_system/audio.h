#pragma once

#include "SpaceModule/s_audio_system/audio_configs.h"
#include "SpaceModule/s_audio_system/audiobuffer.h"
#include "SpaceModule/s_audio_system/audiowaves.h"
#include "SpaceModule/s_audio_system/music_toolkit.h"

namespace SpaceModule {
	inline float dBToVolume(float dB_in) {
		return std::powf(10.f, 0.05f * dB_in);
	}
	inline float VolumeTodB(float vol_in) {
		return 20.f * std::log10f(vol_in);
	}
}