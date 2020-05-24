// Fill out your copyright notice in the Description page of Project Settings.


#include "NeuralNetwork.h"

int UNeuralNetwork::neuroniumOutput(FNeuronium* neuronium) {
	if (neuronium != NULL && neuronium->inputs != NULL && neuronium->input_weights != NULL) {
		float result = 0;
		for (int i = 0; i < neuronium->input_num; i++) {
			result += (neuronium->inputs[i]) * (neuronium->input_weights[i]);
		}
		result += neuronium->bias * 100;
		if (result > 0) return result;
	}
	return 0;
}

TArray<int> UNeuralNetwork::networkOutput(int* inputs, int input_num)
{
	//if (innerNeuroniumLayer.Num() == 0 || outputNeuroniumLayer == nullptr) return nullptr;

	int* innerOutputs = new int[this->inner_num];
	for (int i = 0; i < inner_num; i++) {
		FNeuronium neuronium = innerNeuroniumLayer[i];
		neuronium.inputs = inputs;
		neuronium.input_num = input_num;
		innerOutputs[i] = this->neuroniumOutput(&neuronium);
	}

	TArray<int> outputs;
	for (int i = 0; i < output_num; i++) {
		FNeuronium neuronium = outputNeuroniumLayer[i];
		neuronium.inputs = innerOutputs;
		neuronium.input_num = inner_num;
		outputs.Add(this->neuroniumOutput(&neuronium) > 0 ? 1 : 0);
	}

	delete(innerOutputs);

	return outputs;
}

UNeuralNetwork* UNeuralNetwork::generateNeuralNetwork(int input_num, int output_num)
{
	UNeuralNetwork* network = NewObject<UNeuralNetwork>();

	
	for (int i = 0; i < input_num; i++) {
		FNeuronium newNeuronium;
		newNeuronium.input_weights = new int[input_num];
		newNeuronium.input_num = input_num;
		for (int j = 0; j < input_num; j++) {
			newNeuronium.input_weights[j] = FMath::Rand()%2001 - 1000;
		}
		newNeuronium.bias = FMath::Rand()%2001 - 1000;

		network->innerNeuroniumLayer.Add(newNeuronium);
	}

	network->inner_num = input_num;

	FNeuronium* outputLayer = new FNeuronium[output_num];
	for (int i = 0; i < output_num; i++) {
		FNeuronium newNeuronium;
		newNeuronium.input_weights = new int[input_num];
		newNeuronium.input_num = input_num;
		for (int j = 0; j < input_num; j++) {
			newNeuronium.input_weights[j] = FMath::Rand() % 2001 - 1000;
		}
		newNeuronium.bias = FMath::Rand() % 2001 - 1000;

		network->outputNeuroniumLayer.Add(newNeuronium);
	}

	network->output_num = output_num;

	return network;
}

UNeuralNetwork* UNeuralNetwork::mutateNetwork()
{
	UNeuralNetwork* network = NewObject<UNeuralNetwork>();

	for (int i = 0; i < this->inner_num; i++) {
		network->innerNeuroniumLayer.Add(this->innerNeuroniumLayer[i]);
	}
	network->inner_num = inner_num;
	for (int i = 0; i < this->output_num; i++) {
		network->outputNeuroniumLayer.Add(this->outputNeuroniumLayer[i]);
	}
	network->output_num = output_num;

	return network;
}
