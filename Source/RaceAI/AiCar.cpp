// Fill out your copyright notice in the Description page of Project Settings.


#include "AiCar.h"
#include "AiCar.h"

void AAiCar::BeginPlay()
{
	Super::BeginPlay();
	if (this->isAIControlled) {
		controllerAI = NewObject<UAiCarAIController>();
		controllerAI->BeginPlay();
	}
}

void AAiCar::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (controllerAI == nullptr || !(controllerAI->isAIControlled())) {
		Super::SetupPlayerInputComponent(PlayerInputComponent);
	}
	else {
		Super::Super::SetupPlayerInputComponent(PlayerInputComponent);
	}
}


