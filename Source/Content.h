/*
  ==============================================================================

    Content.h
    Created: 28 Oct 2019 10:32:53am
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LushLookAndFeel.h"
#include "MasterGainMixer.h"
#include "DelaySettings.h"
#include "BufferDrawer.h"

//==============================================================================
/*
*/
class Content    : public Component
{
public:
    Content(LushAudioProcessor&);
    ~Content();

    void paint (Graphics&) override;
    void resized() override;

private:
    LushAudioProcessor& processor;
    
    LushColors lushColors;
    
    MasterGainMixer masterGainMixer;
    DelaySettings delaySettings;
    
    BufferDrawer inBufferDrawer, midBufferDrawer, outBufferDrawer;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Content)
};
