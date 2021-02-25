/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (250, 500);
    
    // Various settings for slider object.
    faderObject.addListener(this);
    faderObject.setSliderStyle(juce::Slider::LinearVertical);
    faderObject.setBounds(75, 83.333, 100, 333.333);
    faderObject.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    faderObject.setRange(0.0, 5.0);
    
    addAndMakeVisible(faderObject);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("Gain Slider", 0, 0, 100, 50, juce::Justification::centred, 1);
    
    g.setFont(10.0f);
    g.drawFittedText("Walker Cullen", 0, 15, 100, 50, juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void NewProjectAudioProcessorEditor::sliderValueChanged(juce::Slider *slider) {
    if(slider == &faderObject){
        audioProcessor.gainMultiplier = slider -> getValue();
    }
}
