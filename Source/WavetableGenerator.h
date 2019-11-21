/*
  ==============================================================================

    WavetableGenerator.h
    Created: 3 Nov 2019 1:16:01pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class WavetableGenerator {
public:
    enum shape {
        sin,
        square,
        triangle
    };
    
    WavetableGenerator();
    
    AudioSampleBuffer sineTable;
    AudioSampleBuffer squareTable;
    AudioSampleBuffer triangleTable;
    
private:
    
    const unsigned int tableSize = 1 << 7;
    
    void draw(AudioSampleBuffer& wavetableBuffer, shape waveShape);
};
