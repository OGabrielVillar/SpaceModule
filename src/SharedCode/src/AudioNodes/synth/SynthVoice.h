#pragma once

#include "SynthSound.h"

namespace AudioNodes
{
	class SynthVoice : public juce::SynthesiserVoice
	{
    public:
		virtual ~SynthVoice() override;

        virtual bool canPlaySound(juce::SynthesiserSound* sound) override;
        //Must return true if this voice object is capable of playing the given sound.More...

        virtual void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
        //Called to start a new note.More...

        virtual void stopNote(float velocity, bool allowTailOff) override;
        //Called to stop a note.More...

        virtual void pitchWheelMoved(int newPitchWheelValue) override;
        //Called to let the voice know that the pitch wheel has been moved.More...

        virtual void controllerMoved(int controllerNumber, int newControllerValue) override;
        //Called to let the voice know that a midi controller has been moved.More...

        virtual void renderNextBlock(juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override;
        //Renders the next block of data for this voice.More...
	};
	
}