// Fill out your copyright notice in the Description page of Project Settings.


#include "ACarPawn.h"


void ACarPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	//Super::Super::SetupPlayerInputComponent(PlayerInputComponent);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
}