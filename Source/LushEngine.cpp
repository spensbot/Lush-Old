/*
  ==============================================================================

    LushEngine.cpp
    Created: 20 Nov 2019 12:58:53pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "LushEngine.h"

LushEngine::LushEngine(AudioProcessorValueTreeState& _parameters)
: parameters(_parameters)
{
    dryDb = parameters.getRawParameterValue("dryGain");
    wetDb = parameters.getRawParameterValue("wetGain");
    delayFeedback = parameters.getRawParameterValue("delayFeedback");
    delayTime = parameters.getRawParameterValue("delayTime");
    delayModDepth = parameters.getRawParameterValue("delayModDepth");
    delayModFrequency = parameters.getRawParameterValue("delayModFrequency");
    
    dryGainRamper.initialize(Decibels::decibelsToGain(*dryDb), 0.001);
    wetGainRamper.initialize(Decibels::decibelsToGain(*wetDb), 0.001);
    
    delayTimeOscillator.reset(*delayModFrequency, *delayTime, *delayModDepth/1000);

    parameters.addParameterListener("dryGain", this);
    parameters.addParameterListener("wetGain", this);
    parameters.addParameterListener("delayFeedback", this);
    parameters.addParameterListener("delayTime", this);
    parameters.addParameterListener("delayModDepth", this);
    parameters.addParameterListener("delayModFrequency", this);
}
LushEngine::~LushEngine(){}

void LushEngine::setSampleRate(double sampleRate)
{
    delayTimeOscillator.sampleRate = sampleRate;
    delayBufferReader.reset(sampleRate);
    leftDelayBuffer.zero(delayBufferReader.getRequiredBufferSize(2.0));
    rightDelayBuffer.zero(delayBufferReader.getRequiredBufferSize(2.0));
}
              
void LushEngine::process(AudioBuffer<float>& buffer)
{
    //Lush Engine is made to be run with 2 channels (left/right)
    
    auto* leftChannel = buffer.getWritePointer(0);
    auto* rightChannel = buffer.getWritePointer(1);
    
    for (auto sample=0 ; sample<buffer.getNumSamples() ; sample ++)
    {
        auto dry = leftChannel[sample];
        auto wet = delayBufferReader.getSample(leftDelayBuffer, delayTimeOscillator.getSample());
        
        leftDelayBuffer.writeSample(dry + wet * *delayFeedback);
        
        leftChannel[sample] = dry * dryGainRamper.getNext() + wet * wetGainRamper.getNext();
        rightChannel[sample] = leftChannel[sample];
    }
}

void LushEngine::parameterChanged(const String& parameterID, float newValue )
{
    if (parameterID == "dryGain") {
        dryGainRamper.updateTarget(Decibels::decibelsToGain(newValue));
    } else if (parameterID == "wetGain") {
        wetGainRamper.updateTarget(Decibels::decibelsToGain(newValue));
    } else {
        delayTimeOscillator.reset(*delayModFrequency, *delayTime, *delayModDepth/1000);
    }
}
