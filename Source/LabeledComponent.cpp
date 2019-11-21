/*
  ==============================================================================

    LabeledComponent.cpp
    Created: 19 Nov 2019 4:06:54pm
    Author:  Spenser Saling

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LabeledComponent.h"

//==============================================================================
LabeledComponent::LabeledComponent(String _title, Component& _child)
:title(_title), child(_child)
{
    addAndMakeVisible(child);
    addAndMakeVisible(label);
    
    label.setText(title, dontSendNotification);
    label.setJustificationType(Justification::centred);
}

LabeledComponent::~LabeledComponent()
{
}

void LabeledComponent::paint (Graphics& g)
{
    
}

void LabeledComponent::resized()
{
    auto titleHeight = 20;
    
    auto localBounds = getLocalBounds();
    label.setBounds(localBounds.removeFromTop(titleHeight));
    child.setBounds(localBounds);
}
