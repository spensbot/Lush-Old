/*
  ==============================================================================

    FilterBase.h
    Created: 25 Nov 2019 5:48:54pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

class FilterBase {
public:
    virtual ~FilterBase(){};
    virtual float getOutput(float input) = 0;
    virtual void setSampleRate(double _sampleRate, double bufferSeconds){};
    virtual void setup(float** params){};
};
