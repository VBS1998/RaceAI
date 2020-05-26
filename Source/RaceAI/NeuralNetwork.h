// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NeuralNetwork.generated.h"

USTRUCT()
struct FNeuronium {
	GENERATED_USTRUCT_BODY()

	int* input_weights;
	int* inputs;
	int input_num;
	int bias;
};

UCLASS()
class RACEAI_API UNeuralNetwork : public UObject
{
	GENERATED_BODY()

private:
	TArray<FNeuronium> innerNeuroniumLayer;
	TArray<FNeuronium> outputNeuroniumLayer;
	int inner_num;
	int output_num;

	int neuroniumOutput(FNeuronium* neuronium);

public:
	TArray<int> networkOutput(int* inputs, int input_num);

	static UNeuralNetwork* generateNeuralNetwork(int input_num, int output_num);
	UNeuralNetwork* mutateNetwork();

	void destroyNeuroniums();

	void loadFromString(FString string);
	FString toString();
};
