// Fill out your copyright notice in the Description page of Project Settings.


#include "AiCar.h"

void AAiCar::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (controllerAI == NULL || !(controllerAI->isAIControlled())) {
		Super::SetupPlayerInputComponent(PlayerInputComponent);
	}
	else {
		Super::Super::SetupPlayerInputComponent(PlayerInputComponent);
	}

}
