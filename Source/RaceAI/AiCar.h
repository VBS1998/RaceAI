// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RaceAIPawn.h"
#include "AiCarAIController.h" 
#include "Containers/UnrealString.h"

#include "WheeledVehicleMovementComponent4W.h"

#include "AiCar.generated.h"

/**
 * 
 */
UCLASS()
class RACEAI_API AAiCar : public ARaceAIPawn
{
	GENERATED_BODY()
private:

	//UPROPERTY(meta = (AllowPrivateAccess = "true"))
	bool isAIControlled = true;

	UAiCarAIController *controllerAI;
protected:
	//arthur//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay)
	FName WallTag;
	//arthur//
public:
	//arthur//
	UFUNCTION(BlueprintCallable)
	void OnWallCollision();
	bool IsCarDead();
	//arthur//

	virtual void BeginPlay() override;
	virtual void Tick(float Delta) override;
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
