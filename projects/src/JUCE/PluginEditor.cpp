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
    setSize (1200, 800);
}

SpaceModuleAudioProcessorEditor::~SpaceModuleAudioProcessorEditor()
{
}

//==============================================================================
void SpaceModuleAudioProcessorEditor::paint (juce::Graphics& g)
{
    m_App->Go(g);
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    std::stringstream text;

    text << "x: "   << std::to_string(mouse_position.x)
         << "\ny: " << std::to_string(mouse_position.y) ;

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText (text.str(), getLocalBounds(), juce::Justification::bottomRight, 1);

    g.setColour(juce::Colour(testColor.r, testColor.g, testColor.b));
    
    g.fillRect((int)mouse_position.x, (int)mouse_position.y, 10, 10);

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
    mouse_position.x = (float)event.getPosition().x;
    mouse_position.y = (float)event.getPosition().y;

    m_App->s_InputSystem->OnMouseMovement(mouse_position);

    repaint();
}

void SpaceModuleAudioProcessorEditor::mouseDown(const juce::MouseEvent& event)
{
    testColor = SpaceModule::rgb(50, 155, 155);
    mouse_position.x = event.getPosition().x;
    mouse_position.y = event.getPosition().y;
    
    if (event.mods.isLeftButtonDown())
    {
        using namespace SpaceModule::Input;
        SpaceModule::InputInfo info(InputCode::MS_LeftButton,InputType::Press,event.position.x, event.position.y);
        m_App->s_InputSystem->InputEvent(info);
    }

    repaint();
}

void SpaceModuleAudioProcessorEditor::mouseUp(const juce::MouseEvent& event)
{
    testColor = SpaceModule::rgb(155, 50, 155);
    mouse_position.x = event.getPosition().x;
    mouse_position.y = event.getPosition().y;

    if (event.mods.isLeftButtonDown())
    {
        using namespace SpaceModule::Input;
        SpaceModule::InputInfo info(InputCode::MS_LeftButton, InputType::Release, event.position.x, event.position.y);
        m_App->s_InputSystem->InputEvent(info);
    }

    repaint();
}
