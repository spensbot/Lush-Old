/*
  ==============================================================================

    LushEngine.h
    Created: 20 Nov 2019 12:58:53pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include "RamperLinear.h"
#include "RecirculatingBuffer.h"
#include "RecirculatingBufferReader.h"

class LushEngine : private AudioProcessorValueTreeState::Listener {
public:
    LushEngine(AudioProcessorValueTreeState&);
    ~LushEngine();
    
    void setSampleRate(double sampleRate);
                  
    void process(AudioBuffer<float>& buffer);
    
    void parameterChanged(const String& parameterID, float newValue ) override;
    
private:
    
    AudioProcessorValueTreeState& parameters;
    
    Oscillator<float> delayTimeOscillator;
    
    float* dryDb;
    float* wetDb;
    float* delayTime;
    float* delayFeedback;
    float* delayModDepth;
    float* delayModFrequency;
    
    RamperLinear dryGainRamper, wetGainRamper;
    
    RecirculatingBuffer rightDelayBuffer, leftDelayBuffer;
    RecirculatingBufferReader delayBufferReader;

};
