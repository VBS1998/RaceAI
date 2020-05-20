// Fill out your copyright notice in the Description page of Project Settings.


#include "AiRaceController.h"

// Sets default values
AAiRaceController::AAiRaceController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAiRaceController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAiRaceController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

