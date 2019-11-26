/*
  ==============================================================================

    DelayFilter.cpp
    Created: 25 Nov 2019 4:23:50pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "DelayFilter.h"

void DelayFilter::setSampleRate(double sampleRate, double maxSeconds){
    bufferReader.reset(sampleRate);
    delayBuffer.zero( (int)(maxSeconds * sampleRate) + 1 );
}

void DelayFilter::setup(float _time, float _fb) {
    time = _time;
    fb = _fb;
}
