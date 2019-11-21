/*
  ==============================================================================

    OscillatingPosition.cpp
    Created: 20 Nov 2019 1:00:22pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "Oscillator.h"


template <typename SampleType>
Oscillator<SampleType>::Oscillator()
{
    
}

template <typename SampleType>
Oscillator<SampleType>::~Oscillator()
{
    
}

template <typename SampleType>
void Oscillator<SampleType>::reset(SampleType frequency, SampleType _offset, SampleType _depth)
{
    SampleType radsPerOscillation = MathConstants<SampleType>::twoPi;
    // frequency is effectively oscillations/second
    SampleType radsPerSecond = radsPerOscillation * frequency;
    // sampleRate is effectively samples/second
    radsPerSample = radsPerSecond / sampleRate;
    
    offset = _offset;
    depth = _depth;
}

template <typename SampleType>
void Oscillator<SampleType>::zero()
{
    pos = 0.0;
}

template <typename SampleType>
SampleType Oscillator<SampleType>::getSample()
{
    SampleType result = std::sin(pos);
    result *= depth;
    result += offset;
    
    increment();
    
    return result;
}

template <typename SampleType>
void Oscillator<SampleType>::increment()
{
    pos += radsPerSample;
    
    if (pos > MathConstants<SampleType>::twoPi)
    {
        pos -= MathConstants<SampleType>::twoPi;
    }
}

template class Oscillator<float>;
template class Oscillator<double>;
