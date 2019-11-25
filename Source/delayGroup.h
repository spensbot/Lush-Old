/*
  ==============================================================================

    DelayGroup.h
    Created: 22 Nov 2019 9:05:27am
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"
#include "RecirculatingBuffer.h"
#include "RecirculatingBufferReader.h"

class DelayGroup {
public:
    
    void setSampleRate(double);
    void update(float time, float depth, float frequency, float spacing, int lines);
    float getNextWet(RecirculatingBuffer& buffer);
    
private:
    Random random;
    double sampleRate;
    OwnedArray<Oscillator<float>> delayOscillators;
    RecirculatingBufferReader delayBufferReader;
};
