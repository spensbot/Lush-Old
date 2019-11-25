/*
  ==============================================================================

    OscillatingPosition.h
    Created: 20 Nov 2019 1:00:22pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

template <typename SampleType>
class Oscillator {
public:
    Oscillator();
    ~Oscillator();
    
    void reset(SampleType frequency, SampleType _offset, SampleType _depth, bool randomPosition);
    void zero();
    
    SampleType getSample();
    
    SampleType sampleRate = 44100.0f;
    
private:
    Random random;
    
    SampleType radsPerSample = 0.0f;
    SampleType pos = 0.0f; //Current oscillator position, in radians.
    SampleType offset = 0.0f; //the base offset.
    SampleType depth = 0.0f; //The oscillation depth.
    
    void increment();
    void randomizePosition();
};
