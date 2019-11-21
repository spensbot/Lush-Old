/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LushAudioProcessorEditor::LushAudioProcessorEditor (LushAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), header(p), content(p), footer(p), debugger(p.debugString)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);
    setLookAndFeel(&lushLookAndFeel);
    
    addAndMakeVisible(header);
    addAndMakeVisible(content);
    addAndMakeVisible(footer);
    
    addAndMakeVisible(debugger);
}

LushAudioProcessorEditor::~LushAudioProcessorEditor()
{
}

//==============================================================================
void LushAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void LushAudioProcessorEditor::resized()
{
    int headerHeight = 25;
    int footerHeight = 25;
    int debuggerWidth = 0;
    
    Rectangle<int> localBounds = getLocalBounds();
    
    debugger.setBounds(localBounds.removeFromRight(debuggerWidth));
    header.setBounds(localBounds.removeFromTop(headerHeight));
    footer.setBounds(localBounds.removeFromBottom(footerHeight));
    content.setBounds(localBounds);
}
