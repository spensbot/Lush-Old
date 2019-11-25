/*
  ==============================================================================

    BufferDrawer.h
    Created: 25 Nov 2019 10:38:28am
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class BufferDrawer    : public Component, private Timer
{
public:
    BufferDrawer(AudioBuffer<float>& buffer);
    ~BufferDrawer();

    void paint (Graphics&) override;
    void resized() override;
    
    void timerCallback () override;

private:
    AudioBuffer<float>& buffer;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BufferDrawer)
};
