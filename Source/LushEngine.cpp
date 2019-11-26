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
    spacing = parameters.getRawParameterValue("spacing");
    delayLines = parameters.getRawParameterValue("delayLines");
    
    dryGainRamper.initialize(Decibels::decibelsToGain(*dryDb), 0.001);
    wetGainRamper.initialize(Decibels::decibelsToGain(*wetDb), 0.001);

    parameters.addParameterListener("dryGain", this);
    parameters.addParameterListener("wetGain", this);
    parameters.addParameterListener("delayFeedback", this);
    parameters.addParameterListener("delayTime", this);
    parameters.addParameterListener("delayModDepth", this);
    parameters.addParameterListener("delayModFrequency", this);
    parameters.addParameterListener("spacing", this);
    parameters.addParameterListener("delayLines", this);
    
    allpassFilters[0].setup(.305, 0.7);
    allpassFilters[1].setup(.037, 0.7);
    allpassFilters[2].setup(.113, 0.7);
    combFilters[0].setup(.773, 0.8);
    combFilters[1].setup(.756, 0.75);
    combFilters[2].setup(.739, 0.7);
}
LushEngine::~LushEngine(){}

void LushEngine::setSampleRate(double _sampleRate)
{
    for (int filter=0 ; filter<3 ; filter++){
        allpassFilters[filter].setSampleRate(_sampleRate, 10.0);
        combFilters[filter].setSampleRate(_sampleRate, 10.0);
    }
    
    int visualBufferSize = 200000; //samples
    
    inBuffer.zero(visualBufferSize);
    midBuffer.zero(visualBufferSize);
    outBuffer.zero(visualBufferSize);
}
              
void LushEngine::process(AudioBuffer<float>& buffer, int startSample, int numSamples)
{
    //Lush Engine is made to be run with 2 channels (left/right)
    auto* leftChannel = buffer.getWritePointer(0);
    auto* rightChannel = buffer.getWritePointer(1);
    
    for (auto sample=0 ; sample<buffer.getNumSamples() ; sample ++)
    {
        auto dry = leftChannel[sample];
        inBuffer.writeSample(dry);
        
        auto wet = allpassFilters[0].getOutput(dry);
        wet += allpassFilters[1].getOutput(wet);
        wet += allpassFilters[2].getOutput(wet);
        
        midBuffer.writeSample(wet);
        
        wet = combFilters[0].getOutput(wet) +
        combFilters[1].getOutput(wet) +
        combFilters[2].getOutput(wet);
        
        leftChannel[sample] = dry * dryGainRamper.getNext() + wet * wetGainRamper.getNext();
        rightChannel[sample] = leftChannel[sample];
        outBuffer.writeSample(leftChannel[sample]);
    }
}

void LushEngine::parameterChanged(const String& parameterID, float newValue )
{
    if (parameterID == "dryGain") {
        dryGainRamper.updateTarget(Decibels::decibelsToGain(newValue));
    } else if (parameterID == "wetGain") {
        wetGainRamper.updateTarget(Decibels::decibelsToGain(newValue));
    } else {
    }
}
