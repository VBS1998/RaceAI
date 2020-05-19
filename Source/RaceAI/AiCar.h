// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RaceAIPawn.h"
#include "AiCarAIController.h" 
#include "AiCar.generated.h"

/**
 * 
 */
UCLASS()
class RACEAI_API AAiCar : public ARaceAIPawn
{
	GENERATED_BODY()
private:

	UPROPERTY(meta = (AllowPrivateAccess = "true"))
	bool isAIControlled;

	UAiCarAIController *controllerAI;

public:
	virtual void BeginPlay() override;
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
