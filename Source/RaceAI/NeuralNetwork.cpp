// Fill out your copyright notice in the Description page of Project Settings.


#include "NeuralNetwork.h"

int UNeuralNetwork::neuroniumOutput(FNeuronium neuronium) {
	float result = 0;
	for (int i = 0; i < neuronium.input_num; i++) {
		result += (neuronium.inputs[i]) * (neuronium.input_weights[i]);
	}
	result += neuronium.bias * 100;
	if (result > 0) return result;
	return 0;
}

TArray<int> UNeuralNetwork::networkOutput(TArray<int> inputs, int input_num)
{
	
	TArray<int> innerOutputs;
	for (int i = 0; i < inner_num; i++) {
		FNeuronium neuronium = innerNeuroniumLayer[i];
		neuronium.inputs = inputs;
		neuronium.input_num = input_num;
		innerOutputs.Add(this->neuroniumOutput(neuronium));
	}

	TArray<int> outputs;
	for (int i = 0; i < output_num; i++) {
		FNeuronium neuronium = outputNeuroniumLayer[i];
		neuronium.inputs = innerOutputs;
		neuronium.input_num = inner_num;
		outputs.Add(this->neuroniumOutput(neuronium) > 0 ? 1 : 0);
	}

	return outputs;
}

UNeuralNetwork* UNeuralNetwork::generateNeuralNetwork(int input_num, int output_num)
{
	UNeuralNetwork* network = NewObject<UNeuralNetwork>();

	
	for (int i = 0; i < input_num; i++) {
		FNeuronium neuronium;
		neuronium.input_num = input_num;
		for (int j = 0; j < input_num; j++) {
			neuronium.input_weights.Add(FMath::Rand()%2001 - 1000);
		}
		neuronium.bias = FMath::Rand()%2001 - 1000;
		network->innerNeuroniumLayer.Add(neuronium);
	}
	network->inner_num = input_num;

	for (int i = 0; i < output_num; i++) {
		FNeuronium neuronium;
		neuronium.input_num = input_num;
		for (int j = 0; j < input_num; j++) {
			neuronium.input_weights.Add(FMath::Rand() % 2001 - 1000);
		}
		neuronium.bias = FMath::Rand() % 2001 - 1000;
		network->outputNeuroniumLayer.Add(neuronium);
	}
	network->output_num = output_num;

	return network;
}
