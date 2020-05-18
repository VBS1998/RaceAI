// Fill out your copyright notice in the Description page of Project Settings.


#include "AiCarAIController.h"

void UAiCarAIController::updateOutputsWith(int speed, int* sensors, int gear)
{
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
	return (neuralNetwork == NULL);
}

void UAiCarAIController::BeginPlay()
{
	this->move_forward = false;
	this->move_back = false;
	this->move_right = false;
	this->move_left = false;
	this->handbreak = false;
}
