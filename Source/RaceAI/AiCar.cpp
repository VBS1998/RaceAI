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

	if (!this->isAIControlled || this->isDead) {
		this->MoveForward(0);
		this->MoveRight(0);
		this->OnHandbrakePressed();
		return;
	}

	int gear = GetVehicleMovement()->GetCurrentGear();
	int speed = GetVehicleMovement()->GetForwardSpeed();
	int* sensors = GetAllSensorsResult();
	controllerAI->updateOutputsWith(speed, gear, sensors, 5);

	if (controllerAI->shouldMoveForward()) this->MoveForward(1);
	if (controllerAI->shouldMoveBack()) this->MoveForward(-1);
	if (!controllerAI->shouldMoveForward() && !controllerAI->shouldMoveBack()) this->MoveForward(0);

	if (controllerAI->shouldMoveRight()) this->MoveRight(1);
	if (controllerAI->shouldMoveLeft()) this->MoveRight(-1);
	if (!controllerAI->shouldMoveRight() && !controllerAI->shouldMoveLeft()) this->MoveRight(0);

	if (controllerAI->shouldBreak()) this->OnHandbrakePressed();
	else this->OnHandbrakeReleased();

	if (bLogActive) LastLogDuration += Delta;

	delete(sensors);
}

void AAiCar::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (this->isAIControlled) {
		Super::Super::SetupPlayerInputComponent(PlayerInputComponent);
	}
	else {
		Super::SetupPlayerInputComponent(PlayerInputComponent);
	}
}

UAiCarAIController* AAiCar::getAIController()
{
	return this->controllerAI;
}

//arthur//
void AAiCar::ResetVars()
{
	isDead = false;
}
void AAiCar::OnWallCollision()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Colidiu!"));
	this->isDead = true;
}

bool AAiCar::IsCarDead()
{
	return this->isDead;
}

int* AAiCar::GetAllSensorsResult()
{
	FVector forwardVector = this->GetActorForwardVector();
	int* sensorsResult = new int[sensorsCount];

	forwardVector = forwardVector.RotateAngleAxis(-(sensorsAngle * (sensorsCount / 2)), FVector::UpVector);
	
	if (bLogActive && LastLogDuration >= 3)
	{
		UE_LOG(LogTemp, Warning, TEXT("---------------------------------------"));
	}
	for (int i = 0; i < sensorsCount; i++)
	{
		if (bLogActive && LastLogDuration >= 3)
		{
			UE_LOG(LogTemp, Warning, TEXT("RayCastHit carro numero: %s FOward Vec: %s Distancia: %s"), *this->GetName(), *forwardVector.ToString(), *FString::FromInt(sensorsResult[i]));
		}
		sensorsResult[i] = (int)SensorRayCast(forwardVector);		
		if (bLogActive) DrawDebugLine(GetWorld(), this->GetActorLocation(), (forwardVector * sensorsResult[i]) + this->GetActorLocation(), FColor::Red, false, -1, 8, 1);

		forwardVector = forwardVector.RotateAngleAxis(sensorsAngle, FVector::UpVector);

		
	}	
	if (bLogActive && LastLogDuration >= 3)
	{
		UE_LOG(LogTemp, Warning, TEXT("---------------------------------------"));
		LastLogDuration = 0;
	}

	return sensorsResult;
}
float AAiCar::SensorRayCast(FVector CastDir)
{
	FVector start;
	FVector end;
	FHitResult outHit;
	FCollisionQueryParams collisionParams;

	start = this->GetActorLocation();
	start.Z = 10.f;
	CastDir.Z = 20.f;
	CastDir = CastDir * 10000.0f;
	CastDir.Z = start.Z;
	end = (CastDir + start);

	collisionParams.AddIgnoredActor(this);


	if (GetWorld()->LineTraceSingleByObjectType(outHit, start, end, ECC_WorldStatic, collisionParams))
	{
		if (Cast<AAiCar>(outHit.Actor) == nullptr)
		{						
			if (bLogActive) DrawDebugLine(GetWorld(), start, outHit.ImpactPoint, FColor::Blue, false, -1, 8, 1);
			return (FVector::Distance(start, outHit.ImpactPoint));
		}
	}

	return -1.f;
}
//arhtur//
