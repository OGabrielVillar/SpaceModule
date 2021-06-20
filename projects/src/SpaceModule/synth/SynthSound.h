#pragma once

#include <JuceHeader.h>

namespace SpaceModule
{

	class SynthSound : public juce::SynthesiserSound
	{
	public:
		~SynthSound() override;

		virtual bool appliesToNote(int) { return true; };

		virtual bool appliesToChannel(int) { return true; };
	};

}

