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
: processor(p), masterGainMixer(p.parameters), delaySettings(p.parameters)
{
    addAndMakeVisible(masterGainMixer);
    addAndMakeVisible(delaySettings);
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
    
    delaySettings.setBounds(localBounds.removeFromLeft(getWidth()/2));
    masterGainMixer.setBounds(localBounds);
    
}
