// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RaceAIPawn.h"
#include "AiCar.generated.h"

/**
 * 
 */
UCLASS()
class RACEAI_API AAiCar : public ARaceAIPawn
{
	GENERATED_BODY()
	
public:
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
