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
: processor(p), masterGainMixer(p.parameters), delaySettings(p.parameters), inBufferDrawer(p.lushEngine.inBuffer.buffer),
    midBufferDrawer(p.lushEngine.midBuffer.buffer),
    outBufferDrawer(p.lushEngine.outBuffer.buffer)
{
    addAndMakeVisible(masterGainMixer);
    addAndMakeVisible(delaySettings);
    addAndMakeVisible(inBufferDrawer);
    addAndMakeVisible(midBufferDrawer);
    addAndMakeVisible(outBufferDrawer);
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
    int bufferHeight = getHeight()/5;
    
    inBufferDrawer.setBounds(localBounds.removeFromTop(bufferHeight));
    outBufferDrawer.setBounds(localBounds.removeFromBottom(bufferHeight));
    midBufferDrawer.setBounds(localBounds.removeFromBottom(bufferHeight));
    delaySettings.setBounds(localBounds.removeFromLeft(getWidth()/2));
    masterGainMixer.setBounds(localBounds);
    
}
