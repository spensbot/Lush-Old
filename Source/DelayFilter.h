/*
  ==============================================================================

    DelayFilter.h
    Created: 25 Nov 2019 4:23:50pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "FilterBase.h"
#include "RecirculatingBuffer.h"
#include "RecirculatingBufferReader.h"

class DelayFilter{
    
public:
    virtual ~DelayFilter(){};
    
    virtual float getOutput(float input) = 0;
    void setSampleRate(double sampleRate, double maxSeconds);
    void setup(float _time, float _fb);
    
    RecirculatingBuffer delayBuffer;
    
protected:
    RecirculatingBufferReader bufferReader;
    
    float time;
    float fb;
};
