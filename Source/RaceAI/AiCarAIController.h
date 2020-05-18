// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NeuralNetwork.h"
#include "AiCarAIController.generated.h"

/**
 * 
 */
UCLASS()
class RACEAI_API UAiCarAIController : public UObject
{
	GENERATED_BODY()

private:
	//Car input variables
	bool move_forward, move_back, move_right, move_left, handbreak;
	//The Neural Network that will define the input variables
	UNeuralNetwork *neuralNetwork;

public:

	//This method will give the Neural Network the inputs and handle the outputs
	void updateOutputsWith(int speed, int *sensors, int gear);

	//These methodes will tell the AiCar which "buttons" it should press 
	bool shouldMoveForward();
	bool shouldMoveBack();
	bool shouldMoveRight();
	bool shouldMoveLeft();
	bool shouldBreak();

	//A method that informs the existence of a Neural Network
	bool isAIControlled();

	
	virtual void BeginPlay();
	
};
