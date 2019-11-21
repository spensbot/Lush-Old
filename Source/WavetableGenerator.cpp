/*
  ==============================================================================

    WavetableGenerator.cpp
    Created: 3 Nov 2019 1:16:01pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "WavetableGenerator.h"

WavetableGenerator::WavetableGenerator(){
    sineTable.setSize(1, tableSize + 1);
    draw(sineTable, sin);
    squareTable.setSize(1, tableSize + 1);
    draw(squareTable, square);
    triangleTable.setSize(1, tableSize + 1);
    draw(triangleTable, triangle);
}

void WavetableGenerator::draw(AudioSampleBuffer& wavetableBuffer, shape waveShape){
    
    jassert (wavetableBuffer.getNumChannels() == 0);
    
    auto pi = MathConstants<double>::pi;
    
    auto tableLength = wavetableBuffer.getNumSamples();
    auto steps = double(tableLength);
    auto radsPerStep = 2.0 * pi / steps;
    auto angle = 0.0;
    double currentVal = 0.0;
    
    auto* samples = wavetableBuffer.getWritePointer(0);
    
    for (int sample=0 ; sample<tableLength ; sample++){
        
        switch (waveShape) {
            case sin:
                currentVal = std::sin(angle);
                samples[sample] = currentVal;
                break;
            case square:
                if (angle < pi){
                    samples[sample] = 1;
                } else {
                    samples[sample] = -1;
                }
                break;
            case triangle:
                samples[sample] = 1 - angle/pi;
                break;
        }
        angle += radsPerStep;
    }
    
    samples[tableLength] = samples[0];
}
