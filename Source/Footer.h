/*
  ==============================================================================

    Footer.h
    Created: 28 Oct 2019 10:30:19am
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
class Footer    : public Component
{
public:
    Footer(LushAudioProcessor&);
    ~Footer();

    void paint (Graphics&) override;
    void resized() override;

private:
    LushAudioProcessor& processor;

    TextButton undoButton;
    TextButton redoButton;
    
    LushColors lushColors;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Footer)
};
