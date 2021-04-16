//
//  APF.hpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#ifndef APF_hpp
#define APF_hpp

#include "FractionalDelay.hpp"
using namespace std;

class APF {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    APF();
    
    APF(float delay , float speed){
        fractionalDelay.setDelaySamples(delay);
        fractionalDelay.setSpeed(speed);
    }
    
    // Destructor
    ~APF();
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setFeedbackGain(float feedbackGain );
    
    void setSpeed(float speed);
    
    void setDepth(float depth);
    
private:
    
    float Fs = 48000.f;
    
    FractionalDelay fractionalDelay {240.f , 0.7f};
    
    float feedbackGain = 0.5f;
    
    float fb1[2] = {0.f};
    
    float speed = 1.0f;
    
    float angleChange = speed * (1.f/Fs) * 2.f * M_PI;
    
    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
};



#endif /* APF_hpp */
