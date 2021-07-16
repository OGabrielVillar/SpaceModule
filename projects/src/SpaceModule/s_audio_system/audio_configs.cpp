#include "audio_configs.h"
namespace SpaceModule {

	float AudioSettings::sampleRate = 0.0f;
	float AudioSettings::sampleTime = 0.0f;

	void AudioSettings::SetSampleRate(float in)
	{
		sampleRate = in;
		sampleTime = 1.f / sampleRate;
	}

	float AudioSettings::GetSampleTime()
	{
		return sampleTime;
	}

}