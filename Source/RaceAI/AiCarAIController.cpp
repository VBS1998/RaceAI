// Fill out your copyright notice in the Description page of Project Settings.


#include "AiCarAIController.h"

void UAiCarAIController::BeginPlay()
{
	this->move_forward = false;
	this->move_back = false;
	this->move_right = false;
	this->move_left = false;
	this->handbreak = false;

	this->neuralNetwork = NeuralNetwork::generateNeuralNetwork(2, 5);
}

void UAiCarAIController::updateOutputsWith(int speed, int gear, int* sensors, int sensors_num)
{
	int* inputs = new int[sensors_num+2];
	inputs[0] = speed;
	inputs[1] = gear;
	for (int i = 0; i < sensors_num; i++) {
		inputs[i+2] = sensors[i];
	}

	int* outputs = this->neuralNetwork->networkOutput(inputs, sensors_num + 2);

	this->move_forward = outputs[0] == 1 ? true : false;
	this->move_back = outputs[1] == 1 ? true : false;
	this->move_right = outputs[2] == 1 ? true : false;
	this->move_left = outputs[3] == 1 ? true : false;
	this->handbreak = outputs[4] == 1 ? true : false;

	delete(outputs);
	delete(inputs);

}

bool UAiCarAIController::shouldMoveForward()
{
	return this->move_forward;
}

bool UAiCarAIController::shouldMoveBack()
{
	return this->move_back;
}

bool UAiCarAIController::shouldMoveRight()
{
	return this->move_right;
}

bool UAiCarAIController::shouldMoveLeft()
{
	return this->move_left;
}

bool UAiCarAIController::shouldBreak()
{
	return this->handbreak;
}

bool UAiCarAIController::isAIControlled()
{
	return (neuralNetwork == nullptr);
}


