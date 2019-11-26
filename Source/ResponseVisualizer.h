/*
  ==============================================================================

    ResponseVisualizer.h
    Created: 26 Nov 2019 9:28:08am
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "BufferDrawer.h"
#include "LushEngine.h"

//==============================================================================
/*
*/
class ResponseVisualizer    : public Component, private Slider::Listener
{
public:
    ResponseVisualizer(AudioProcessorValueTreeState&);
    ~ResponseVisualizer();

    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;

private:
    double sampleRate = 44100.0;
    double maxLength = 5.0;
    
    Slider lengthSlider;
    Label lengthLabel;
    
    BufferDrawer bufferDrawer;
    
    AudioBuffer<float> inputBuffer;
    
    LushEngine lushEngine;
    
    void processBuffer(float seconds);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ResponseVisualizer)
};
