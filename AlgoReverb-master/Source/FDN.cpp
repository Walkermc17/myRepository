//
//  FDN.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "FDN.hpp"
#include <math.h>

FDN::FDN(){
}

// Destructor
FDN::~FDN(){
}


float FDN::processSample(float x, int channel){
    
    float y;
    float inDL1 = x + fb1[channel];
    float inDL2 = x + fb2[channel];
    float inDL3 = x + fb3[channel];
    float inDL4 = x + fb4[channel];
    
    float outDL1 = fractionalDelay1.processSample(inDL1 , channel);
    float outDL2 = fractionalDelay2.processSample(inDL2 , channel);
    float outDL3 = fractionalDelay3.processSample(inDL3 , channel);
    float outDL4 = fractionalDelay4.processSample(inDL4 , channel);
    
    y = 0.35f * (outDL1 + outDL2 + outDL3 + outDL4);
    
    fb1[channel] = (-outDL2 + outDL3) * feedbackGain;
    fb2[channel] = (outDL1 + outDL4) * feedbackGain;
    fb3[channel] = (outDL1 + -outDL4) * feedbackGain;
    fb4[channel] = (-outDL2 + -outDL3) * feedbackGain;
        
    return y;
}

void FDN::setFs(float Fs){
    this->Fs = Fs;
    fractionalDelay1.setFs(Fs);
    fractionalDelay2.setFs(Fs);
}

void FDN::setSpeed(float speed){
    if (speed >= 0.1f && speed <= 10.0f){
        this->speed = speed;
        angleChange = speed * (1.f/Fs) * 2 * M_PI;
    }
}

void FDN::setDepth(float depth){

    this->depth = depth;
    fractionalDelay1.setDepth(depth);
    fractionalDelay2.setDepth(depth);
    fractionalDelay3.setDepth(depth);
    fractionalDelay4.setDepth(depth);
}

void FDN::setTime(float timeValue){
    feedbackGain = timeValue;
}
