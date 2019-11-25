/*
  ==============================================================================

    Content.cpp
    Created: 28 Oct 2019 10:32:53am
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Content.h"


//==============================================================================
Content::Content(LushAudioProcessor& p)
: processor(p), masterGainMixer(p.parameters), delaySettings(p.parameters), bufferDrawer(p.lushEngine.leftDelayBuffer.buffer)
{
    addAndMakeVisible(masterGainMixer);
    addAndMakeVisible(delaySettings);
    addAndMakeVisible(bufferDrawer);
}

Content::~Content()
{
}

void Content::paint (Graphics& g)
{
    g.fillAll (lushColors.contentBackground);
}

void Content::resized()
{
    auto localBounds = getLocalBounds();
    
    bufferDrawer.setBounds(localBounds.removeFromTop(getHeight()/3));
    delaySettings.setBounds(localBounds.removeFromLeft(getWidth()/2));
    masterGainMixer.setBounds(localBounds);
    
}
