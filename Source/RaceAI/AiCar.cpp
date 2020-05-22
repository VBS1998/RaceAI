// Fill out your copyright notice in the Description page of Project Settings.


#include "AiCar.h"

void AAiCar::BeginPlay()
{
	if (this->isAIControlled) {
		controllerAI = NewObject<UAiCarAIController>();
		controllerAI->BeginPlay();
	}
	Super::BeginPlay();
	
}

void AAiCar::Tick(float Delta)
{
	Super::Tick(Delta);

	int gear = GetVehicleMovement()->GetCurrentGear();
	int speed = GetVehicleMovement()->GetForwardSpeed();
	TArray<int> sensors;
	controllerAI->updateOutputsWith(speed, gear, sensors, 0);
	if (controllerAI->shouldMoveForward()) this->MoveForward(1);
	if (controllerAI->shouldMoveBack()) this->MoveForward(-1);
	if (controllerAI->shouldMoveRight()) this->MoveRight(1);
	if (controllerAI->shouldMoveLeft()) this->MoveRight(-1);
}

void AAiCar::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (this->isAIControlled) {
		Super::SetupPlayerInputComponent(PlayerInputComponent);
	}
	else {
		Super::Super::SetupPlayerInputComponent(PlayerInputComponent);
	}
}

//arthur//
void AAiCar::OnWallCollision()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Collidiu!"));
	//implementa ai papito
}

bool AAiCar::IsCarDead()
{
	return false; //implementa ai papiro
}
//arhtur//
