/*
  ==============================================================================

    AllpassFilter.h
    Created: 25 Nov 2019 4:14:04pm
    Author:  Spenser Saling

  ==============================================================================
*/

#pragma once
#include "DelayFilter.h"

class AllpassFilter: public DelayFilter {
    
public:
    float getOutput(float input) override;
    
private:
    
};
