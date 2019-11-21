/*
  ==============================================================================

    Footer.cpp
    Created: 28 Oct 2019 10:30:19am
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Footer.h"

//==============================================================================
Footer::Footer(LushAudioProcessor& p)
: processor(p)
{
    undoButton.setButtonText("undo");
    redoButton.setButtonText("redo");
    addAndMakeVisible(undoButton);
    addAndMakeVisible(redoButton);
    undoButton.onClick = [this] { processor.undoManager.undo(); };
    redoButton.onClick = [this] { processor.undoManager.redo(); };
}

Footer::~Footer()
{
}

void Footer::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
    
    g.setColour(lushColors.border);
    g.drawRect(getLocalBounds().removeFromTop(1));
}

void Footer::resized()
{
    int padding = 5;
    int width = 50;
    
    Rectangle<int> localBounds = getLocalBounds();
    localBounds.reduce(padding, padding);
    undoButton.setBounds(localBounds.removeFromLeft(width));
    localBounds.removeFromLeft(padding);
    redoButton.setBounds(localBounds.removeFromLeft(width));
}
