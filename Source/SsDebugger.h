/*
  ==============================================================================

    SsDebugger.h
    Created: 29 Oct 2019 12:45:47pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "LushLookAndFeel.h"

//==============================================================================
/*
*/
class SsDebugger    : public Component, private Timer
{
public:
    SsDebugger(String&);
    ~SsDebugger();

    void paint (Graphics&) override;
    void resized() override;
    
    void timerCallback() override;

private:
    TextEditor debugField;
    String& debugString;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SsDebugger)
};


