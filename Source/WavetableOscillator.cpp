/*
  ==============================================================================

    WavetableOscillator.cpp
    Created: 3 Nov 2019 12:06:40pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "WavetableOscillator.h"

WavetableOscillator::WavetableOscillator ()
{
    
}

WavetableOscillator::~WavetableOscillator(){ }

void WavetableOscillator::setup(float frequency, float sampleRate){
    auto stepsPerSecond = tableSize * frequency;
    stepsPerSample = stepsPerSecond / sampleRate;
}
void WavetableOscillator::restart(){
    position = 0.0f;
}
void WavetableOscillator::setTable(AudioSampleBuffer* _wavetable){
    wavetable = _wavetable;
    tableSize = wavetable->getNumSamples();
    jassert (wavetable->getNumChannels() == 1);
}

float WavetableOscillator::getNextSample(){
    float currentSample = 0.0f;
    if (wavetable != nullptr) {
        auto tableSize = wavetable->getNumSamples();
        auto index0 = (unsigned int) position;
        auto index1 = index0 + 1;
    
        auto frac = position - (float) index0;
    
        auto* table = wavetable->getReadPointer(0);
        auto value0 = table[index0];
        auto value1 = table[index1];
    
        currentSample = value0 + frac*(value1-value0);
    
        if ((position += stepsPerSample) > tableSize)
            position -= tableSize;
    }
    
    return currentSample;
}
