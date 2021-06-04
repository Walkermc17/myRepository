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

    //==============================================================================
    // SET BACKGROUND
    //==============================================================================
    auto backgroundImage = ImageCache::getFromMemory(BinaryData::MainBackground_png, BinaryData::MainBackground_pngSize);
    
    if (! backgroundImage.isNull()) {
        backgroundImageComponent.setImage(backgroundImage,RectanglePlacement::stretchToFit);
    }
    else {
        jassert (! backgroundImage.isNull());
    }
    
    addAndMakeVisible(backgroundImageComponent);
    
    //==============================================================================
    // SET DEFAULT FONT
    //==============================================================================
    LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypefaceName("Avenir Next");
    setFontParameters(&font);
    
    //==============================================================================
    // SLIDERS
    //==============================================================================
    
    //REVERB TIME SLIDER
    reverbTimeSlider.setRange(0.4f, 0.7f, 0.01f);
    reverbTimeSlider.setValue(0.6f);
    reverbTimeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    reverbTimeSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(reverbTimeSlider);
    
    reverbTimeSlider.setLookAndFeel(&smallKnob);
    
    reverbTimeLabel.setText("Time", dontSendNotification);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider, false);
    reverbTimeLabel.setFont(font);
    reverbTimeLabel.setColour(Label::textColourId, Colours::silver);
    reverbTimeLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(reverbTimeLabel);
    
    //MODULATION SLIDER
    modulationSlider.setRange(1.0f, 10.f, 0.01f);
    modulationSlider.setValue(5.0f);
    modulationSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    modulationSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(modulationSlider);
    
    modulationSlider.setLookAndFeel(&smallKnob);
    
    modulationLabel.setText("Depth", dontSendNotification);
    modulationLabel.attachToComponent(&modulationSlider, false);
    modulationLabel.setFont(font);
    modulationLabel.setColour(Label::textColourId, Colours::silver);
    modulationLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(modulationLabel);
    
    //MODSPEED SLIDER
    modSpeedSlider.setRange(0.1f, 1.0f, 0.01f);
    modSpeedSlider.setValue(.5f);
    modSpeedSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    modSpeedSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(modSpeedSlider);
    
    modSpeedSlider.setLookAndFeel(&smallKnob);
    
    modSpeedLabel.setText("Rate", dontSendNotification);
    modSpeedLabel.attachToComponent(&modSpeedSlider, false);
    modSpeedLabel.setFont(font);
    modSpeedLabel.setColour(Label::textColourId, Colours::silver);
    modSpeedLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(modSpeedLabel);
    
    //WETDRY SLIDER
    wetDrySlider.setRange(0.0f, 1.0f, 0.01f);
    wetDrySlider.setValue(0.5f);
    wetDrySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    wetDrySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(wetDrySlider);
    
    wetDrySlider.setLookAndFeel(&largeKnob);
    
    wetDryLabel.setText("Dry/Wet", dontSendNotification);
    wetDryLabel.attachToComponent(&wetDrySlider, false);
    wetDryLabel.setFont(font);
    wetDryLabel.setColour(Label::textColourId, Colours::silver);
    wetDryLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(wetDryLabel);
    
    //PREDELAY SLIDER
    predelaySlider.setRange(0.0f, 200.0f, 0.1f);
    predelaySlider.setValue(0.0f);
    predelaySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    predelaySlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(predelaySlider);
    
    predelaySlider.setLookAndFeel(&smallKnob);
    
    predelayLabel.setText("Predelay", dontSendNotification);
    predelayLabel.attachToComponent(&predelaySlider, false);
    predelayLabel.setFont(font);
    predelayLabel.setColour(Label::textColourId, Colours::silver);
    predelayLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(predelayLabel);
    
    //DIFFUSION SLIDER
    diffusionSlider.setRange(0.2f, 0.8f, 0.01f);
    diffusionSlider.setValue(0.4f);
    diffusionSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    diffusionSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(diffusionSlider);
    
    diffusionSlider.setLookAndFeel(&smallKnob);
    
    diffusionLabel.setText("Diffusion", dontSendNotification);
    diffusionLabel.attachToComponent(&diffusionSlider, false);
    diffusionLabel.setFont(font);
    diffusionLabel.setColour(Label::textColourId, Colours::silver);
    diffusionLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(diffusionLabel);
    
    //LPF SLIDER
    lpfSlider.setRange(100.0f, 20000.0f, 1.0f);
    lpfSlider.setValue(10000.f);
    lpfSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    lpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(lpfSlider);
    
    lpfSlider.setLookAndFeel(&smallKnob);
    
    lpfLabel.setText("LPF", dontSendNotification);
    lpfLabel.attachToComponent(&lpfSlider, false);
    lpfLabel.setFont(font);
    lpfLabel.setColour(Label::textColourId, Colours::silver);
    lpfLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(lpfLabel);
    
    //HPF SLIDER
    hpfSlider.setRange(100.0f, 20000.0f, 1.0f);
    hpfSlider.setValue(250.f);
    hpfSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    hpfSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(hpfSlider);
    
    hpfSlider.setLookAndFeel(&smallKnob);
    
    hpfLabel.setText("HPF", dontSendNotification);
    hpfLabel.attachToComponent(&hpfSlider, false);
    hpfLabel.setFont(font);
    hpfLabel.setColour(Label::textColourId, Colours::silver);
    hpfLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(hpfLabel);
    
    //==============================================================================
    // ATTACHMENTS
    //==============================================================================
    
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "timeValue", reverbTimeSlider));
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "modValue", modulationSlider));
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "modSpeed", modSpeedSlider));
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "wet", wetDrySlider));
    
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "predelayMS", predelaySlider));
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "diffusionValue", diffusionSlider));
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "freqValueLow", lpfSlider));
    sliderAttachments.emplace_back(new AudioProcessorValueTreeState::SliderAttachment(processor.state, "freqValueHigh", hpfSlider));
    
    setSize (400, 300);
    setResizable(false, false);
    
}

AlgoReverbAudioProcessorEditor::~AlgoReverbAudioProcessorEditor()
{
}

//==============================================================================
void AlgoReverbAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void AlgoReverbAudioProcessorEditor::resized()
{
    backgroundImageComponent.setBounds(0.f, 0.f, 400.f, 300.f);
    
    reverbTimeSlider.setBounds(2.5, 30, 100, 100);
    modulationSlider.setBounds(102.5, 30, 100, 100);
    modSpeedSlider.setBounds(202.5, 30, 100, 100);
    wetDrySlider.setBounds(302.5, 30, 100, 100);
    predelaySlider.setBounds(2.5, 175, 100, 100);
    diffusionSlider.setBounds(102.5, 175, 100, 100);
    lpfSlider.setBounds(202.5, 175, 100, 100);
    hpfSlider.setBounds(302.5, 175, 100, 100);
}

void AlgoReverbAudioProcessorEditor::setFontParameters(Font* font) {
    font->setTypefaceName("Avenir Next");
    font->setTypefaceStyle("Demi Bold");
    font->setHeight(20);
}


