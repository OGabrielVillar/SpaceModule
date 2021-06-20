/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AudioNodes/Application.h"

//==============================================================================
/**
*/
class AudioNodesAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AudioNodesAudioProcessorEditor (AudioNodesAudioProcessor&);
    ~AudioNodesAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    std::unique_ptr<AudioNodes::Application> m_App;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioNodesAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioNodesAudioProcessorEditor)
};
