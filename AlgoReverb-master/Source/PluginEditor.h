/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SmallKnob.h"
#include "LargeKnob.h"

//==============================================================================
/**
*/
class AlgoReverbAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor&);
    ~AlgoReverbAudioProcessorEditor() override;

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void setFontParameters(Font* font);
    
    std::vector<std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment>> sliderAttachments;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AlgoReverbAudioProcessor& processor;
    
    ImageComponent backgroundImageComponent;
    
    Slider reverbTimeSlider;
    Slider modulationSlider;
    Slider modSpeedSlider;
    Slider wetDrySlider;
    
    Slider predelaySlider;
    Slider diffusionSlider;
    Slider lpfSlider;
    Slider hpfSlider;
    
    Label reverbTimeLabel;
    Label modulationLabel;
    Label modSpeedLabel;
    Label wetDryLabel;
    
    Label predelayLabel;
    Label diffusionLabel;
    Label lpfLabel;
    Label hpfLabel;
    
    SmallKnob smallKnob;
    LargeKnob largeKnob;
    
    Font font;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AlgoReverbAudioProcessorEditor)
};


