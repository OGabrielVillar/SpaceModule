/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SpaceModule/core/Application.h"

//==============================================================================
/**
*/
class SpaceModuleAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SpaceModuleAudioProcessorEditor (SpaceModuleAudioProcessor&);
    ~SpaceModuleAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    std::unique_ptr<SpaceModule::Application> m_App;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SpaceModuleAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpaceModuleAudioProcessorEditor)
};
