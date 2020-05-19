// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NeuralNetwork.generated.h"


typedef struct{

	float* input_weights;
	int* inputs;
	int input_num;
	float bias;
}Neuronium;

/**
 * 
 */
UCLASS()
class RACEAI_API UNeuralNetwork : public UObject
{
	GENERATED_BODY()

private:
	Neuronium* innerNeuroniumLayer;
	Neuronium* outputNeuroniumLayer;
	int inner_num;
	int output_num;

	int neuroniumOutput(Neuronium* neuronium);
	
public:

	int* networkOutput(int* inputs, int input_num);
};
