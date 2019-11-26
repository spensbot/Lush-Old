/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LushAudioProcessor::LushAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
#endif
parameters (*this, &undoManager, Identifier ("APVTSTutorial"),
{
    std::make_unique<AudioParameterFloat> ("dryGain", "Dry Gain", -100.0f, 6.0f, -0.0f), //dB
    std::make_unique<AudioParameterFloat> ("wetGain", "Wet Gain", -100.0f, 6.0f, -6.0f), //dB
    std::make_unique<AudioParameterFloat> ("delayFeedback", "Delay Feedback", 0.0f, 1.0f, 0.75f),
    std::make_unique<AudioParameterFloat> ("delayTime", "Delay Time", 5.0f, 2000.0f, 10.0f), //ms
    std::make_unique<AudioParameterFloat> ("delayModDepth", "Delay Mod Depth", 0.0f, 2.0f, 0.0f), //ms
    std::make_unique<AudioParameterFloat> ("delayModFrequency", "Delay Mod Frequency", 0.0f, 5.0f, 2.0f), //hz
    std::make_unique<AudioParameterFloat> ("spacing", "Spacing", 0.0f, 500.0f, 10.0f), //ms
    std::make_unique<AudioParameterInt> ("delayLines", "Delay Lines", 1, 10, 1)
}),
lushEngine(parameters)
{
    
}

LushAudioProcessor::~LushAudioProcessor()
{
    
}

//==============================================================================
const String LushAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool LushAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool LushAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool LushAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double LushAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int LushAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int LushAudioProcessor::getCurrentProgram()
{
    return 0;
}

void LushAudioProcessor::setCurrentProgram (int index)
{
}

const String LushAudioProcessor::getProgramName (int index)
{
    return {};
}

void LushAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void LushAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    lushEngine.setSampleRate(sampleRate);
}

void LushAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool LushAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
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

void LushAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    
    lushEngine.process(buffer, 0, buffer.getNumSamples());
}

//==============================================================================
bool LushAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* LushAudioProcessor::createEditor()
{
    return new LushAudioProcessorEditor (*this);
}

//==============================================================================
void LushAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml (state.createXml());
    copyXmlToBinary(*xml, destData);
}

void LushAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState (getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(ValueTree::fromXml(*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new LushAudioProcessor();
}
