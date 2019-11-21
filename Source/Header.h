/*
  ==============================================================================

    Header.h
    Created: 28 Oct 2019 10:30:04am
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "LushLookAndFeel.h"

//==============================================================================
/*
*/
class Header    : public Component
{
public:
    Header(LushAudioProcessor&);
    ~Header();

    void paint (Graphics&) override;
    void resized() override;

private:
    LushAudioProcessor& processor;
    
    LushColors lushColors;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
