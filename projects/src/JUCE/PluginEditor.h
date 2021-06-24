/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Platforms/juce/JuceApplication.h"

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
    void mouseMove(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
private:
    Scope<JuceApplication> m_App;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SpaceModuleAudioProcessor& audioProcessor;
    glm::vec<2, int, glm::qualifier::defaultp> mouse_position;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpaceModuleAudioProcessorEditor)
};
