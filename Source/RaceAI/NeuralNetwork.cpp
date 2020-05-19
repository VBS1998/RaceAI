// Fill out your copyright notice in the Description page of Project Settings.


#include "NeuralNetwork.h"

int UNeuralNetwork::neuroniumOutput(Neuronium* neuronium) {
	if (neuronium != NULL && neuronium->inputs != NULL && neuronium->input_weights != NULL) {
		float result = 0;
		for (int i = 0; i < neuronium->input_num; i++) {
			result += (neuronium->inputs[i]) * (neuronium->input_weights[i]);
		}
		result += neuronium->bias;
		if (result > 0) return result;
	}
	return 0;
}

int* UNeuralNetwork::networkOutput(int* inputs, int input_num)
{
	if (innerNeuroniumLayer == nullptr || outputNeuroniumLayer == nullptr) return nullptr;

	int* innerOutputs = new int[this->inner_num];
	for (int i = 0; i < inner_num; i++) {
		Neuronium* neuronium = &innerNeuroniumLayer[i];
		neuronium->inputs = inputs;
		neuronium->input_num = input_num;
		innerOutputs[i] = this->neuroniumOutput(neuronium);
	}

	int* outputs = new int[this->output_num];
	for (int i = 0; i < output_num; i++) {
		Neuronium* neuronium = &outputNeuroniumLayer[i];
		neuronium->inputs = inputs;
		neuronium->input_num = inner_num;
		outputs[i] = this->neuroniumOutput(neuronium);
	}

	return outputs;
}
