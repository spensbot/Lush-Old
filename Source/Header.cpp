/*
  ==============================================================================

    Header.cpp
    Created: 28 Oct 2019 10:30:04am
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Header.h"

//==============================================================================
Header::Header(LushAudioProcessor& p)
: processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Header::~Header()
{
}

void Header::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
    
    g.setColour(lushColors.border);
    g.drawRect(getLocalBounds().removeFromBottom(1));
}

void Header::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
}
