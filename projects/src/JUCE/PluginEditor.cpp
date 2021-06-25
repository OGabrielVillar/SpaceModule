/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include <sstream>

//==============================================================================
SpaceModuleAudioProcessorEditor::SpaceModuleAudioProcessorEditor (SpaceModuleAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
      m_App(new JuceApplication())
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

SpaceModuleAudioProcessorEditor::~SpaceModuleAudioProcessorEditor()
{
}

//==============================================================================
void SpaceModuleAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    std::stringstream text;

    text << "x: "   << std::to_string(mouse_position.x)
         << "\ny: " << std::to_string(mouse_position.y) ;

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText (text.str(), getLocalBounds(), juce::Justification::bottomRight, 1);

    g.setColour(juce::Colour(255, 100, 255));
    
    g.fillRect(mouse_position.x, mouse_position.y, 10, 10);

    m_App->Go(g);
}

void SpaceModuleAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    m_App->WhenResized(getWidth(), getHeight());
    repaint();
}

void SpaceModuleAudioProcessorEditor::mouseMove(const juce::MouseEvent& event)
{
    mouse_position.x = event.getPosition().x;
    mouse_position.y = event.getPosition().y;
    repaint();
}

void SpaceModuleAudioProcessorEditor::mouseDown(const juce::MouseEvent& event)
{
    mouse_position.x = event.getPosition().x;
    mouse_position.y = event.getPosition().y;
    repaint();
}
