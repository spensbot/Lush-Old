/*
  ==============================================================================

    MasterGainMixer.cpp
    Created: 19 Nov 2019 3:52:28pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MasterGainMixer.h"

//==============================================================================
MasterGainMixer::MasterGainMixer(AudioProcessorValueTreeState& _parameters)
: parameters(_parameters), dryGainComponent("Dry", dryGainSlider), wetGainComponent("Wet", wetGainSlider)
{
    drySliderAttachment.reset(new SliderAttachment(parameters, "dryGain", dryGainSlider));
    wetSliderAttachment.reset(new SliderAttachment(parameters, "wetGain", wetGainSlider));
    
    addAndMakeVisible(wetGainComponent);
    addAndMakeVisible(dryGainComponent);
    
    wetGainSlider.setSliderStyle(Slider::LinearVertical);
    dryGainSlider.setSliderStyle(Slider::LinearVertical);
    wetGainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dryGainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
}

MasterGainMixer::~MasterGainMixer()
{
    
}

void MasterGainMixer::paint (Graphics& g)
{
    
}

void MasterGainMixer::resized()
{
    auto localBounds = getLocalBounds();
    
    dryGainComponent.setBounds(localBounds.removeFromLeft(getWidth()/2));
    wetGainComponent.setBounds(localBounds);
}
