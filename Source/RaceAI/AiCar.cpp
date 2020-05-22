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
	controllerAI->updateOutputsWith(speed, gear, nullptr, 0);
	if (controllerAI->shouldMoveForward()) this->MoveForward(1);
	if (controllerAI->shouldMoveBack()) this->MoveForward(-1);
	if (controllerAI->shouldMoveRight()) this->MoveRight(1);
	if (controllerAI->shouldMoveLeft()) this->MoveRight(-1);

	//arthur//
	LastLogDuration += Delta;

	SensorRayCasts();
	//arthur//
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

void AAiCar::SensorRayCasts()
{
	FVector start;
	FVector forwardVector;
	FVector end;
	FHitResult outHit;
	FCollisionQueryParams collisionParams;


	forwardVector = this->GetActorForwardVector();
	forwardVector.Z = 0;
	start = this->GetActorLocation();
	start.Z = 50.0f;
	end = ((forwardVector * 10000.0f) + start);

	DrawDebugLine(GetWorld(), start, end, FColor::Green, false, -1, 8, 1);
	if (GetWorld()->LineTraceSingleByChannel(outHit, start, end, ECC_Destructible, collisionParams))
	{
		if (outHit.bBlockingHit)
		{
			if (GEngine && (LastLogDuration > 5.f))
			{
				//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, FString::Printf(TEXT("Acertou o: %s, a distancia: %d"), *outHit.GetActor()->GetName(), ((int)outHit.Distance)));
				LastLogDuration = 0;
			}
		}
	}
}
//arhtur//
