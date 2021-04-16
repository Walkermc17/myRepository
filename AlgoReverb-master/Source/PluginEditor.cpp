/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AlgoReverbAudioProcessorEditor::AlgoReverbAudioProcessorEditor (AlgoReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    //REVERB TIME SLIDER
    //reverbTimeSlider.addListener(this); UNNECESSARY WITH VALUE TREE STATE
    reverbTimeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    reverbTimeSlider.setBounds(2.5, 30, 100, 100);
    reverbTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    reverbTimeSlider.setRange(0.4f, 0.7f, 0.01f);
    //reverbTimeSlider.setValue(0.5f); UNNECESSARY WITH VALUE TREE STATE
    addAndMakeVisible(reverbTimeSlider);
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "timeValue", reverbTimeSlider));
    
    reverbTimeLabel.setText("Time", dontSendNotification);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider, false);
    reverbTimeLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(reverbTimeLabel);
    
    //MODULATION SLIDER
    //modulationSlider.addListener(this); UNNECESSARY WITH VALUE TREE STATE
    modulationSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    modulationSlider.setBounds(102.5, 30, 100, 100);
    modulationSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    modulationSlider.setRange(1.0f, 10.f, 0.01f);
    //modulationSlider.setValue(1.0f); UNNECESSARY WITH VALUE TREE STATE
    addAndMakeVisible(modulationSlider);
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "modValue", modulationSlider));
    
    modulationLabel.setText("Depth", dontSendNotification);
    modulationLabel.attachToComponent(&modulationSlider, false);
    modulationLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(modulationLabel);
    
    //MODSPEED SLIDER
    //modSpeedSlider.addListener(this); UNNECESSARY WITH VALUE TREE STATE
    modSpeedSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    modSpeedSlider.setBounds(202.5, 30, 100, 100);
    modSpeedSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    modSpeedSlider.setRange(0.0f, 1.0f, 0.01f);
    //modSpeedSlider.setValue(0.5f); UNNECESSARY WITH VALUE TREE STATE
    addAndMakeVisible(modSpeedSlider);
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "modSpeed", modSpeedSlider));
    
    modSpeedLabel.setText("Rate", dontSendNotification);
    modSpeedLabel.attachToComponent(&modSpeedSlider, false);
    modSpeedLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(modSpeedLabel);
    
    //WETDRY SLIDER
    //wetDrySlider.addListener(this); UNNECESSARY WITH VALUE TREE STATE
    wetDrySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    wetDrySlider.setBounds(302.5, 30, 100, 100);
    wetDrySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    wetDrySlider.setRange(0.0f, 1.0f, 0.01f);
    //wetDrySlider.setValue(0.5f); UNNECESSARY WITH VALUE TREE STATE
    addAndMakeVisible(wetDrySlider);
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "wet", wetDrySlider));
    
    wetDryLabel.setText("Dry/Wet", dontSendNotification);
    wetDryLabel.attachToComponent(&wetDrySlider, false);
    wetDryLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(wetDryLabel);
    
    //PREDELAY SLIDER
    //predelaySlider.addListener(this); UNNECESSARY WITH VALUE TREE STATE
    predelaySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    predelaySlider.setBounds(2.5, 175, 100, 100);
    predelaySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    predelaySlider.setRange(0.0f, 200.0f, 0.1f);
    //predelaySlider.setValue(0.0f); UNNECESSARY WITH VALUE TREE STATE
    addAndMakeVisible(predelaySlider);
    //sliderAttachments = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.state, "predelayMS", predelaySlider);
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "predelayMS", predelaySlider));
    
    predelayLabel.setText("Predelay", dontSendNotification);
    predelayLabel.attachToComponent(&predelaySlider, false);
    predelayLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(predelayLabel);
    
    //DIFFUSION SLIDER
    //diffusionSlider.addListener(this); UNNECESSARY WITH VALUE TREE STATE
    diffusionSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    diffusionSlider.setBounds(102.5, 175, 100, 100);
    diffusionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    diffusionSlider.setRange(0.2f, 0.8f, 0.01f);
    //diffusionSlider.setValue(0.5f); UNNECESSARY WITH VALUE TREE STATE
    addAndMakeVisible(diffusionSlider);
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "diffusionValue", predelaySlider));
    
    diffusionLabel.setText("Diffusion", dontSendNotification);
    diffusionLabel.attachToComponent(&diffusionSlider, false);
    diffusionLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(diffusionLabel);
    
    //LPF SLIDER
    //lpfSlider.addListener(this); UNNECESSARY WITH VALUE TREE STATE
    lpfSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    lpfSlider.setBounds(202.5, 175, 100, 100);
    lpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    lpfSlider.setRange(100.0f, 20000.0f, 1.0f);
    //lpfSlider.setValue(10000.0f); UNNECESSARY WITH VALUE TREE STATE
    addAndMakeVisible(lpfSlider);
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "freqValueLow", lpfSlider));
    
    lpfLabel.setText("LPF", dontSendNotification);
    lpfLabel.attachToComponent(&lpfSlider, false);
    lpfLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(lpfLabel);
    
    //HPF SLIDER
    //hpfSlider.addListener(this); UNNECESSARY WITH VALUE TREE STATE
    hpfSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    hpfSlider.setBounds(302.5, 175, 100, 100);
    hpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    hpfSlider.setRange(100.0f, 20000.0f, 1.0f);
    //hpfSlider.setValue(1000.0f); UNNECESSARY WITH VALUE TREE STATE
    addAndMakeVisible(hpfSlider);
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "freqValueHigh", hpfSlider));
    
    hpfLabel.setText("HPF", dontSendNotification);
    hpfLabel.attachToComponent(&hpfSlider, false);
    hpfLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(hpfLabel);
    
}

AlgoReverbAudioProcessorEditor::~AlgoReverbAudioProcessorEditor()
{
}

//==============================================================================
void AlgoReverbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);
}

void AlgoReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

/*void AlgoReverbAudioProcessorEditor::sliderValueChanged(Slider *slider){
    if (slider == & predelaySlider){
        processor.predelayMS = predelaySlider.getValue();
    }
    
    if (slider == & wetDrySlider){
        processor.wet = wetDrySlider.getValue();
    }
    
    if (slider == & reverbTimeSlider){
        processor.timeValue = reverbTimeSlider.getValue();
    }
    
    if (slider == & modulationSlider){
        processor.modValue = modulationSlider.getValue();
    }
    
    if (slider == & diffusionSlider){
        processor.diffusionValue = diffusionSlider.getValue();
    }
    
    if (slider == & lpfSlider){
        processor.freqValueLow = lpfSlider.getValue();
    }
    
    if (slider == & hpfSlider){
        processor.freqValueHigh = hpfSlider.getValue();
    }
}
UNNECESSARY WITH VALUE TREE STATE*/

