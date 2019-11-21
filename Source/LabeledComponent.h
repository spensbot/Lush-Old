/*
  ==============================================================================

    LabeledComponent.h
    Created: 19 Nov 2019 4:06:54pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "LushLookAndFeel.h"

//==============================================================================
/*
*/
class LabeledComponent    : public Component
{
public:
    LabeledComponent(String _title, Component& _child);
    ~LabeledComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    LushColors lushColors;
    String title;
    Component& child;
    Label label;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LabeledComponent)
};
