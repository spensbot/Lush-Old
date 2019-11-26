/*
  ==============================================================================

    CombFilter.h
    Created: 25 Nov 2019 4:14:12pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "DelayFilter.h"

class CombFilter: public DelayFilter {
    
public:
    float getOutput(float input) override;
    
private:
    
};

