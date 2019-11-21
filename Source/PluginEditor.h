/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Header.h"
#include "Content.h"
#include "Footer.h"
#include "SsDebugger.h"
#include "LushLookAndFeel.h"

//==============================================================================
/**
*/
class LushAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    LushAudioProcessorEditor (LushAudioProcessor&);
    ~LushAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    LushAudioProcessor& processor;
    
    LushLookAndFeel lushLookAndFeel;
    
    Header header;
    Content content;
    Footer footer;
    
    SsDebugger debugger;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LushAudioProcessorEditor)
};
