/*
  ==============================================================================

    AllpassFilter.cpp
    Created: 25 Nov 2019 4:14:04pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "AllpassFilter.h"

float AllpassFilter::getOutput(float input) {
    
    float feedback = bufferReader.getSample(delayBuffer, time);
    
    feedback = -(feedback * fb);
    
    float feedForward = (input + feedback) * fb;
    
    delayBuffer.writeSample(feedForward);
    
    return feedback + feedForward;
    
}
