/*
  ==============================================================================

    WavetableOscillator.h
    Created: 3 Nov 2019 12:06:40pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class WavetableOscillator {
public:
    WavetableOscillator();
    ~WavetableOscillator();
    
    void setup(float frequency, float sampleRate);
    void setTable(AudioSampleBuffer*);
    void restart();
    
    float getNextSample();
    
private:
    const AudioSampleBuffer* wavetable = nullptr;
    int tableSize;
    float position = 0.0f, stepsPerSample = 0.0f;
};
