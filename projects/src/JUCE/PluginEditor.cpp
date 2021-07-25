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
      m_App(), m_keyM(new KeyManager(m_App))
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 800);
    audioProcessor.LinkApp(&m_App);
    addKeyListener(m_keyM);
    getExplicitFocusOrder();
}

SpaceModuleAudioProcessorEditor::~SpaceModuleAudioProcessorEditor()
{
    delete m_keyM;
}

//==============================================================================
void SpaceModuleAudioProcessorEditor::paint (juce::Graphics& g)
{
    m_App.Render(g);
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void SpaceModuleAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    m_App.WhenResized(getWidth(), getHeight());
    repaint();
}

void SpaceModuleAudioProcessorEditor::mouseMove(const juce::MouseEvent& event)
{
    m_App.s_InputSystem->OnMouseMovement( glm::vec2( event.position.x,event.position.y ) );

    repaint();
}

void SpaceModuleAudioProcessorEditor::mouseDrag(const juce::MouseEvent& event)
{
    mouseMove(event);
}

void SpaceModuleAudioProcessorEditor::mouseDown(const juce::MouseEvent& event)
{    
    if (event.mods.isLeftButtonDown())
    {
        using namespace SpaceModule::Input;
        SpaceModule::InputInfo info(InputCode::MS_LeftButton,InputType::Press,event.position.x, event.position.y);
        m_App.s_InputSystem->InputEvent(info);
    }
    if (event.mods.isRightButtonDown())
    {
        using namespace SpaceModule::Input;
        SpaceModule::InputInfo info(InputCode::MS_RightButton, InputType::Press, event.position.x, event.position.y);
        m_App.s_InputSystem->InputEvent(info);
    }
    if (event.mods.isMiddleButtonDown())
    {
        using namespace SpaceModule::Input;
        SpaceModule::InputInfo info(InputCode::MS_MiddleButton, InputType::Press, event.position.x, event.position.y);
        m_App.s_InputSystem->InputEvent(info);
    }

    repaint();
}

void SpaceModuleAudioProcessorEditor::mouseUp(const juce::MouseEvent& event)
{
    if (event.mods.isLeftButtonDown())
    {
        using namespace SpaceModule::Input;
        SpaceModule::InputInfo info(InputCode::MS_LeftButton, InputType::Release, event.position.x, event.position.y);
        m_App.s_InputSystem->InputEvent(info);
    }
    if (event.mods.isRightButtonDown())
    {
        using namespace SpaceModule::Input;
        SpaceModule::InputInfo info(InputCode::MS_RightButton, InputType::Release, event.position.x, event.position.y);
        m_App.s_InputSystem->InputEvent(info);
    }
    if (event.mods.isMiddleButtonDown())
    {
        using namespace SpaceModule::Input;
        SpaceModule::InputInfo info(InputCode::MS_MiddleButton, InputType::Release, event.position.x, event.position.y);
        m_App.s_InputSystem->InputEvent(info);
    }

    repaint();
}