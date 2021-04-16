/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "FractionalDelay.hpp"
#include "FDN.hpp"
#include "APF.hpp"
#include "Schroeder.hpp"
#include "LowPassFilter.hpp"
#include "HighPassFilter.hpp"

//==============================================================================
/**
*/
class AlgoReverbAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AlgoReverbAudioProcessor();
    ~AlgoReverbAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //float predelayMS = 0.f; UNNECESSARY WITH VALUE TREE STATE
    //float wet = 0.5f;
    float timeValue = 0.5f;
    /*float modSpeed = 1.f;
    float modValue = 1.f;
    float diffusionValue = 0.5f;
    float freqValueLow = 10000.f;
    float freqValueHigh = 1000.f;*/
    
    //==============================================================================
    
    AudioProcessorValueTreeState state;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
private:
    
    FractionalDelay predelay;
    FDN fdn;
    APF apf1{240.f, 0.8321f};
    APF apf2{82.f , 0.9640f};
    
    LowPassFilter lowPassFilter;
    HighPassFilter highPassFilter;
    
    ///Schroeder schroeder;
    
    float Fs = 48000.0f;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AlgoReverbAudioProcessor)
};
