#pragma once

namespace SpaceModule {
	class AudioSettings {
	public:
		static void SetSampleRate(float in);
		static float GetSampleTime();
	private:
		static float sampleRate;
		static float sampleTime;
	};

	inline float sample_time() {
		return AudioSettings::GetSampleTime();
	}
}
