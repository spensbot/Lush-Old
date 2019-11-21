/*
  ==============================================================================

    MasterGainMixer.h
    Created: 19 Nov 2019 3:52:28pm
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
class MasterGainMixer    : public Component
{
public:
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
    MasterGainMixer(AudioProcessorValueTreeState& _parameters);
    ~MasterGainMixer();

    void paint (Graphics&) override;
    void resized() override;

private:
    AudioProcessorValueTreeState& parameters;
    
    DecibelSlider dryGainSlider;
    DecibelSlider wetGainSlider;
    
    LabeledComponent dryGainComponent;
    LabeledComponent wetGainComponent;
    
    std::unique_ptr<SliderAttachment> drySliderAttachment;
    std::unique_ptr<SliderAttachment> wetSliderAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterGainMixer)
};
