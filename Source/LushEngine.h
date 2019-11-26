/*
  ==============================================================================

    LushEngine.h
    Created: 20 Nov 2019 12:58:53pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "RamperLinear.h"
#include "CombFilter.h"
#include "AllpassFilter.h"

class LushEngine : private AudioProcessorValueTreeState::Listener {
public:
    LushEngine(AudioProcessorValueTreeState&);
    ~LushEngine();
    
    void setSampleRate(double);
                  
    void process(AudioBuffer<float>& buffer, int startSample, int numSamples);
    
    void parameterChanged(const String& parameterID, float newValue ) override;
    
    RecirculatingBuffer inBuffer, midBuffer, outBuffer;
    
private:
    
    AllpassFilter allpassFilters[3];
    CombFilter combFilters[3];
    
    AudioProcessorValueTreeState& parameters;
    
    float* dryDb,
    * wetDb,
    * delayTime,
    * delayFeedback,
    * delayModDepth,
    * delayModFrequency,
    * spacing,
    * delayLines;
    
    RamperLinear dryGainRamper, wetGainRamper;

};
