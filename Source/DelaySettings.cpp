/*
  ==============================================================================

    DelaySettings.cpp
    Created: 19 Nov 2019 6:38:21pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "DelaySettings.h"

//==============================================================================
DelaySettings::DelaySettings(AudioProcessorValueTreeState& _parameters)
: parameters(_parameters),
feedbackComponent("Feedback", feedbackSlider),
delayTimeComponent("Delay (s)", delayTimeSlider),
delayModDepthComponent("Mod Depth (ms)", delayModDepthSlider),
delayModFrequencyComponent("Mod Hz", delayModFrequencySlider),
spacingComponent("Spacing", spacingSlider),
delayLinesComponent("Lines", delayLinesComponent)

{
    feedbackSliderAttachment.reset(new SliderAttachment(parameters, "delayFeedback", feedbackSlider));
    delayTimeSliderAttachment.reset(new SliderAttachment(parameters, "delayTime", delayTimeSlider));
    delayModDepthSliderAttachment.reset(new SliderAttachment(parameters, "delayModDepth", delayModDepthSlider));
    delayModFrequencySliderAttachment.reset(new SliderAttachment(parameters, "delayModFrequency", delayModFrequencySlider));
    spacingSliderAttachment.reset(new SliderAttachment(parameters, "spacing", spacingSlider));
    delayLinesSliderAttachment.reset(new SliderAttachment(parameters, "delayLines", delayLinesSlider));
    
    addAndMakeVisible(feedbackComponent);
    addAndMakeVisible(delayTimeComponent);
    addAndMakeVisible(delayModDepthComponent);
    addAndMakeVisible(delayModFrequencyComponent);
    addAndMakeVisible(spacingComponent);
    addAndMakeVisible(delayLinesComponent);
    
    feedbackSlider.setSliderStyle(Slider::LinearVertical);
    feedbackSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    delayTimeSlider.setSliderStyle(Slider::LinearVertical);
    delayTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    delayModDepthSlider.setSliderStyle(Slider::LinearVertical);
    delayModDepthSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    delayModFrequencySlider.setSliderStyle(Slider::LinearVertical);
    delayModFrequencySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    spacingSlider.setSliderStyle(Slider::LinearVertical);
    spacingSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    delayLinesSlider.setSliderStyle(Slider::LinearVertical);
    delayLinesSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
    
}

DelaySettings::~DelaySettings()
{
}

void DelaySettings::paint (Graphics& g)
{
    
}

void DelaySettings::resized()
{
    FlexBox fb;                                          // [1]
    fb.flexDirection = FlexBox::Direction::row;
    fb.flexWrap = FlexBox::Wrap::noWrap;                   // [2]
    fb.justifyContent = FlexBox::JustifyContent::center; // [3]
    fb.alignContent = FlexBox::AlignContent::center;     // [4]
    fb.items.add (FlexItem(feedbackComponent).withFlex(1.0).withHeight(getHeight()));
    fb.items.add (FlexItem(delayTimeComponent).withFlex(1.0).withHeight(getHeight()));
    fb.items.add (FlexItem(delayModDepthComponent).withFlex(1.0).withHeight(getHeight()));
    fb.items.add (FlexItem(delayModFrequencyComponent).withFlex(1.0).withHeight(getHeight()));
    fb.items.add (FlexItem(spacingComponent).withFlex(1.0).withHeight(getHeight()));
    fb.items.add (FlexItem(delayLinesComponent).withFlex(1.0).withHeight(getHeight()));
    fb.performLayout (getLocalBounds().toFloat());       // [6]
}
