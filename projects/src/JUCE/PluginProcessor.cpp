/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "../SpaceModule/synth/SynthVoice.h"

//==============================================================================
SpaceModuleAudioProcessor::SpaceModuleAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    synth.addSound(new SpaceModule::SynthSound());
    synth.addVoice(new SpaceModule::SynthVoice());
}

SpaceModuleAudioProcessor::~SpaceModuleAudioProcessor()
{
}

//==============================================================================
const juce::String SpaceModuleAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SpaceModuleAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SpaceModuleAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SpaceModuleAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SpaceModuleAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SpaceModuleAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SpaceModuleAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SpaceModuleAudioProcessor::setCurrentProgram (int index)
{
    index;
    return;
}

const juce::String SpaceModuleAudioProcessor::getProgramName (int index)
{
    index;
    return {};
}

void SpaceModuleAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
    index;
    newName;
    return;
}

//==============================================================================
void SpaceModuleAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    synth.setCurrentPlaybackSampleRate(sampleRate);
    samplesPerBlock;
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void SpaceModuleAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SpaceModuleAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SpaceModuleAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    midiMessages;

    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
    
    for (size_t i = 0; i < synth.getNumVoices(); i++)
    {
        if (auto voice = dynamic_cast<juce::SynthesiserVoice*>(synth.getVoice(i)))
        {
            //Osc controls
            //ADSR
            //LFO
        }
    }

    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool SpaceModuleAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SpaceModuleAudioProcessor::createEditor()
{
    return new SpaceModuleAudioProcessorEditor (*this);
}

//==============================================================================
void SpaceModuleAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    destData;
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SpaceModuleAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    sizeInBytes;
    data;
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SpaceModuleAudioProcessor();
}
