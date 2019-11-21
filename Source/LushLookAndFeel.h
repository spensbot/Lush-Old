/*
  ==============================================================================

    LushLookAndFeel.h
    Created: 19 Nov 2019 2:00:06pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class LushLookAndFeel : public LookAndFeel_V4
{
public:
    LushLookAndFeel() {
        setColour(ResizableWindow::backgroundColourId, Colour::fromHSV(0.0, 0.0, 0.0, 1.0));
    };
    
};

struct LushColors {
    
    LushColors()
    : contentBackground(Colour::fromHSV(0.0,0.0,0.0,1.0)),
    border(Colour::fromHSV(0.5,0.8,0.8,1.0))
    {
        
    }
    
    const Colour
    contentBackground,
    border;
};


