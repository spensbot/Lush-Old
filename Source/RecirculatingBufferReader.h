/*
  ==============================================================================

    RecirculatingBufferReader.h
    Created: 9 Nov 2019 2:57:40pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "RecirculatingBuffer.h"

class RecirculatingBufferReader {
public:
    RecirculatingBufferReader()
    {
        
    };
    
    ~RecirculatingBufferReader()
    {
        
    };
    
    void reset(float _sampleRate) {
        sampleRate = _sampleRate;
    }
    
    float getSample(RecirculatingBuffer& buffer, float offsetSeconds) {
        int offsetSamples = (int) (sampleRate * offsetSeconds);
        return buffer.getSample(offsetSamples);
    }
    
    int getRequiredBufferSize(float maxDelaySeconds) {
        return (int)(maxDelaySeconds * sampleRate) + 1;
    }
    
private:
    float sampleRate = 0.0; //hertz
};
