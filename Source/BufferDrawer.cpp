/*
  ==============================================================================

    BufferDrawer.cpp
    Created: 25 Nov 2019 10:38:28am
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "BufferDrawer.h"

//==============================================================================
BufferDrawer::BufferDrawer(AudioBuffer<float>& _buffer)
:buffer(_buffer)
{
    startTimerHz(30);
}

BufferDrawer::~BufferDrawer()
{
}

void BufferDrawer::paint (Graphics& g)
{
 

    g.fillAll (Colours::black);
    
    int height = getHeight();
    float center = (float)height/2.0f;
    int width = getWidth();
    
    int samplesPerPixel = buffer.getNumSamples() / width;
    int nextStartSample = 0;
    
    for (int pixel=0 ; pixel<width ; pixel++){
        
        g.setColour (Colour::fromHSV((float)pixel/(float)width, 1.0, 1.0, 1.0));
        
        float rms = buffer.getRMSLevel(0, nextStartSample, samplesPerPixel);
        
        float length = rms * center;
        float startY = center - length;
        float endY = startY + length * 2.0f;
        
        g.drawLine(pixel, startY, pixel, endY);
        
        nextStartSample += samplesPerPixel;
    }

}

void BufferDrawer::resized()
{
    
}

void BufferDrawer::timerCallback() {
    repaint();
}
