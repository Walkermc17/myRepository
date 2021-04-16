//
//  APF.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "APF.hpp"
#include <math.h>

APF::APF(){
}

// Destructor
APF::~APF(){
}


float APF::processSample(float x, int channel){
    
    float y;
    
    float inDL1 = x + (-feedbackGain) * fb1[channel];
    
    float outDL1 = fractionalDelay.processSample(inDL1 , channel);
    
    y = outDL1 + feedbackGain*inDL1;
    
    fb1[channel] = outDL1;
        
    return y;
}

void APF::setFs(float Fs){
    this->Fs = Fs;
    fractionalDelay.setFs(Fs);
}

void APF::setFeedbackGain(float feedbackGain){
    this->feedbackGain = feedbackGain;
}

void APF::setSpeed(float speed){
    if (speed >= 0.1f && speed <= 10.0f){
        this->speed = speed;
        angleChange = speed * (1.f/Fs) * 2 * M_PI;
    }
}

void APF::setDepth(float depth){
    this->depth = depth;
    fractionalDelay.setDepth(depth); //Do I really need both of these?
}
