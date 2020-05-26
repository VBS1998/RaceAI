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
			newNeuronium.input_weights[j] = (FMath::Rand()%2001) - 1000;
		}
		newNeuronium.bias = (FMath::Rand()%2001) - 1000;

		network->innerNeuroniumLayer.Add(newNeuronium);
	}

	network->inner_num = input_num;

	FNeuronium* outputLayer = new FNeuronium[output_num];
	for (int i = 0; i < output_num; i++) {
		FNeuronium newNeuronium;
		newNeuronium.input_weights = new int[input_num];
		newNeuronium.input_num = input_num;
		for (int j = 0; j < input_num; j++) {
			newNeuronium.input_weights[j] = (FMath::Rand() % 2001) - 1000;
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
		//UE_LOG(LogTemp, Warning, TEXT("before %d"), this->innerNeuroniumLayer[i].input_weights[0]);
		FNeuronium neuronium = this->innerNeuroniumLayer[i];
		neuronium.input_weights = new int[neuronium.input_num];
		for (int j = 0; j < neuronium.input_num; j++) {
			neuronium.input_weights[j] = this->innerNeuroniumLayer[i].input_weights[j];
			if(FMath::Rand()%100 > 5)
			neuronium.input_weights[FMath::Rand() % neuronium.input_num] = (FMath::Rand() % 2001) - 1000;
		}
		neuronium.bias += (FMath::Rand() % 401) - 200;
		network->innerNeuroniumLayer.Add(neuronium);
		//UE_LOG(LogTemp, Warning, TEXT("after %d"), this->innerNeuroniumLayer[i].input_weights[0]);
	}
	network->inner_num = inner_num;
	for (int i = 0; i < this->output_num; i++) {
		FNeuronium neuronium = this->outputNeuroniumLayer[i];

		neuronium.input_weights = new int[neuronium.input_num];
		for (int j = 0; j < neuronium.input_num; j++) {
			neuronium.input_weights[j] = this->outputNeuroniumLayer[i].input_weights[j];
			if (FMath::Rand() % 100 > 5)
			neuronium.input_weights[FMath::Rand() % neuronium.input_num] = (FMath::Rand() % 2001) - 1000;
		}
		neuronium.bias += (FMath::Rand() % 201) - 100;
		network->outputNeuroniumLayer.Add(neuronium);
	}
	network->output_num = output_num;

	return network;
}

void UNeuralNetwork::destroyNeuroniums()
{
	for (int i = 0; i < inner_num; i++) {
		delete(innerNeuroniumLayer[i].input_weights);
		if(innerNeuroniumLayer[i].inputs != nullptr)
			delete(innerNeuroniumLayer[i].inputs);
	}
	for (int i = 0; i < output_num; i++) {
		delete(outputNeuroniumLayer[i].input_weights);
		if (outputNeuroniumLayer[i].inputs != nullptr)
			delete(outputNeuroniumLayer[i].inputs);
	}
}

void UNeuralNetwork::loadFromString(FString string)
{
	TArray<FString> array;
	FString space = " ";
	int string_num = string.ParseIntoArray(array, *space, true);

	int iterator = 0;

	this->inner_num = FCString::Atoi(*array[iterator++]);

	for (int i = 0; i < inner_num; i++) {
		FNeuronium neuronium;
		neuronium.input_num = FCString::Atoi(*array[iterator++]);
		neuronium.input_weights = new int[neuronium.input_num];
		for (int j = 0; j < neuronium.input_num; j++) {
			neuronium.input_weights[j] = FCString::Atoi(*array[iterator++]);
		}
		neuronium.bias = FCString::Atoi(*array[iterator++]);
		innerNeuroniumLayer.Add(neuronium);
	}

	this->output_num = FCString::Atoi(*array[iterator++]);

	for(int i = 0; i < output_num; i++){
		FNeuronium neuronium;
		neuronium.input_num = FCString::Atoi(*array[iterator++]);
		neuronium.input_weights = new int[neuronium.input_num];
		for (int j = 0; j < neuronium.input_num; j++) {
			neuronium.input_weights[j] = FCString::Atoi(*array[iterator++]);
		}
		neuronium.bias = FCString::Atoi(*array[iterator++]);
		outputNeuroniumLayer.Add(neuronium);
	}
}

FString UNeuralNetwork::toString()
{
	FString string = "";

	string.Append(FString::FromInt(inner_num));
	
	string.AppendChar(' ');

	for (int i = 0; i < inner_num; i++) {
		string.Append(FString::FromInt(innerNeuroniumLayer[i].input_num));
		string.AppendChar(' ');
		for (int j = 0; j < innerNeuroniumLayer[i].input_num; j++) {
			string.Append(FString::FromInt(innerNeuroniumLayer[i].input_weights[j]));
			string.AppendChar(' ');
		}
		string.Append(FString::FromInt(innerNeuroniumLayer[i].bias));
		string.AppendChar(' ');
	}

	string.Append(FString::FromInt(output_num));

	string.AppendChar(' ');

	for (int i = 0; i < output_num; i++) {
		string.Append(FString::FromInt(outputNeuroniumLayer[i].input_num));
		string.AppendChar(' ');
		for (int j = 0; j < outputNeuroniumLayer[i].input_num; j++) {
			string.Append(FString::FromInt(outputNeuroniumLayer[i].input_weights[j]));
			string.AppendChar(' ');
		}
		string.Append(FString::FromInt(outputNeuroniumLayer[i].bias));
		string.AppendChar(' ');
	}

	return string;
}
