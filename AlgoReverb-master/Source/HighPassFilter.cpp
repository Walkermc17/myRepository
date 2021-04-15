//
//  HighPassFilter.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "HighPassFilter.hpp"
#include <math.h>


HighPassFilter::HighPassFilter(){
}

// Destructor
HighPassFilter::~HighPassFilter(){
}


float HighPassFilter::processSample(float x, int channel){
    
    float y;
    
    y = b0 * x + b1 * x1[channel] + b2 * x2[channel] + (-a1) * y1[channel] + (-a2) * y2[channel];
    
    x2[channel] = x1[channel];
    x1[channel] = x;
    y2[channel] = y1[channel];
    y1[channel] = y;
        
    return y;
}

void HighPassFilter::setFs(float Fs){
    this->Fs = Fs;
}

void HighPassFilter::setFrequency(float newFreq){
    if (freq != newFreq){
        updateCoefficients();
        freq = newFreq;
    }
}

void HighPassFilter::updateCoefficients(){
    float w0 = (2.f * M_PI) * freq / Fs;
    float alpha = sin(w0) / (2.f * Q);
    float cw0 = cos(w0);
    
    a0 = 1.f + alpha;
    
    float B0 = (1.f + cw0) / 2.f;
    b0 = B0/a0;
    
    float B1 = -(1.f + cw0);
    b1 = B1/a0;
    
    b2 = b0;
    
    float A1 = -2.f * cw0;
    a1 = A1/a0;
    
    float A2 = 1.f - alpha;
    a2 = A2/a0;
}
