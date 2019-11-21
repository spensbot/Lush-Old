/*
  ==============================================================================

    DelaySettings.h
    Created: 19 Nov 2019 6:38:21pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DecibelSlider.h"
#include "LabeledComponent.h"

//==============================================================================
/*
*/
class DelaySettings    : public Component
{
public:
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
    DelaySettings(AudioProcessorValueTreeState& _parameters);
    ~DelaySettings();

    void paint (Graphics&) override;
    void resized() override;

private:
    AudioProcessorValueTreeState& parameters;
    
    Slider feedbackSlider;
    Slider delayTimeSlider;
    Slider delayModDepthSlider;
    Slider delayModFrequencySlider;
    Slider spacingSlider;
    Slider delayLinesSlider;
    
    LabeledComponent feedbackComponent;
    LabeledComponent delayTimeComponent;
    LabeledComponent delayModDepthComponent;
    LabeledComponent delayModFrequencyComponent;
    LabeledComponent spacingComponent;
    LabeledComponent delayLinesComponent;
    
    
    std::unique_ptr<SliderAttachment> feedbackSliderAttachment;
    std::unique_ptr<SliderAttachment> delayTimeSliderAttachment;
    std::unique_ptr<SliderAttachment> delayModDepthSliderAttachment;
    std::unique_ptr<SliderAttachment> delayModFrequencySliderAttachment;
    std::unique_ptr<SliderAttachment> spacingSliderAttachment;
    std::unique_ptr<SliderAttachment> delayLinesSliderAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelaySettings)
};
