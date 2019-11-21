/*
  ==============================================================================

    SsDebugger.cpp
    Created: 29 Oct 2019 12:45:47pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SsDebugger.h"

//==============================================================================
SsDebugger::SsDebugger(String& _debugString) : debugString(_debugString)
{
    addAndMakeVisible(debugField);
    
    debugField.setMultiLine(true);
    
    startTimer(100);
}

SsDebugger::~SsDebugger()
{
}

void SsDebugger::paint (Graphics& g)
{
    g.fillAll (Colours::white);
    
    debugField.setText(debugString);
}

void SsDebugger::resized()
{
    debugField.setBounds(5, 5, getWidth()-10, getHeight()-10);
}

void SsDebugger::timerCallback() {
    repaint();
}
