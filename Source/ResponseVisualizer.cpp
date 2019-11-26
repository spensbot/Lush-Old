/*
  ==============================================================================

    ResponseVisualizer.cpp
    Created: 26 Nov 2019 9:28:08am
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "ResponseVisualizer.h"

//==============================================================================
ResponseVisualizer::ResponseVisualizer(AudioProcessorValueTreeState& parameters) :
bufferDrawer(inputBuffer)
, lushEngine(parameters)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    addAndMakeVisible(bufferDrawer);
    addAndMakeVisible(lengthSlider);
    addAndMakeVisible(lengthLabel);
    
    lengthLabel.setJustificationType(Justification::right);
    
    lengthSlider.setSliderStyle(Slider::LinearVertical);
    lengthSlider.setRange(0.1, maxLength);
    lengthSlider.setValue(0.5);
    lengthSlider.addListener(this);
    
    lushEngine.setSampleRate(sampleRate);
    processBuffer(5.0);
    
    bufferDrawer.type = BufferDrawer::Type::max;
}

ResponseVisualizer::~ResponseVisualizer()
{
}

void ResponseVisualizer::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
//
//    g.setColour (Colours::grey);
//    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
//
//    g.setColour (Colours::white);
//    g.setFont (14.0f);
//    g.drawText ("ResponseVisualizer", getLocalBounds(),
//                Justification::centred, true);   // draw some placeholder text
}

void ResponseVisualizer::resized()
{
    Rectangle<int> localBounds = getLocalBounds();
    
    bufferDrawer.setBounds(localBounds);
    lengthSlider.setBounds(localBounds.removeFromRight(30));
    lengthLabel.setBounds(localBounds.removeFromTop(30));
}

void ResponseVisualizer::sliderValueChanged(Slider* slider){
    String formattedLength = String::formatted("%0.2f s", slider->getValue());
    lengthLabel.setText(formattedLength, dontSendNotification);
    
    int numSamples = (int)(sampleRate * slider->getValue());
    bufferDrawer.setWindow(0, numSamples);
}

void ResponseVisualizer::processBuffer(float seconds){
    int numSamples = (int)(sampleRate * seconds);
    
    inputBuffer.setSize(2, numSamples);
    
    inputBuffer.clear();
    
    float value = 1.0;

    for (int sample = 0; sample < 1 ; sample++){
        inputBuffer.setSample(0, sample, value);
        inputBuffer.setSample(1, sample, value);
        //value = -value;
    }
    
    lushEngine.process(inputBuffer, 0, inputBuffer.getNumSamples());
}
