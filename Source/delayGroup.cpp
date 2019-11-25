/*
  ==============================================================================

    DelayGroup.cpp
    Created: 22 Nov 2019 9:05:27am
    Author:  Spenser Saling

  ==============================================================================
*/

#include "DelayGroup.h"

void DelayGroup::setSampleRate(double _sampleRate){
    sampleRate = _sampleRate;
    delayBufferReader.reset(sampleRate);
    for (auto i=0 ; i<delayOscillators.size() ; i++){
        delayOscillators[i]->sampleRate = sampleRate;
    }
}

void DelayGroup::update(float time, float depth, float frequency, float spacing, int lines)
{
    //First, remove unnecessary delay lines.
    if (lines < delayOscillators.size()) {
        delayOscillators.removeLast(delayOscillators.size() - lines);
    }
    
    //Next, update the time, depth, frequency, and spacing of existing lines.
    for (auto i=0; i<delayOscillators.size() ; i++) {
        float delayTime = time + i * spacing;
        delayOscillators[i]->reset(frequency, delayTime, depth, false);
    }
    
    //Last, add any new delay lines with given properties.
    if (lines > delayOscillators.size()) {
        for (auto i=0; i<lines-delayOscillators.size() ; i++){
            float delayTime = time + i * spacing;// + spacing*random.nextFloat()/2;
            
            Oscillator<float>* newOscillator = new Oscillator<float>();
            newOscillator->reset(frequency, delayTime, depth, false);
            newOscillator->sampleRate = sampleRate;
            delayOscillators.add(newOscillator);
        }
    }
}

float DelayGroup::getNextWet(RecirculatingBuffer& buffer)
{
    float wet = 0.0f;
    float weight = 1.0f / (float)delayOscillators.size();
    for (auto i=0 ; i<delayOscillators.size() ; i++) {
        float offsetSeconds = delayOscillators[i]->getSample();
        wet += delayBufferReader.getSample(buffer, offsetSeconds) * weight;
    }
    return wet;
}
