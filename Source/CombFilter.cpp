/*
  ==============================================================================

    CombFilter.cpp
    Created: 25 Nov 2019 4:14:12pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "CombFilter.h"

float CombFilter::getOutput(float input) {
    float feedback = bufferReader.getSample(delayBuffer, time);
    feedback *= fb;
    float bufferInput = feedback + input;
    
    delayBuffer.writeSample(bufferInput);
    return bufferInput;
}
