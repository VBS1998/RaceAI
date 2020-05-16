// Fill out your copyright notice in the Description page of Project Settings.


#include "ACarAIController.h"

// Sets default values
AACarAIController::AACarAIController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AACarAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AACarAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

