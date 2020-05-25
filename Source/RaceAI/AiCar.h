// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RaceAIPawn.h"
#include "AiCarAIController.h" 
#include "Containers/UnrealString.h"

#include "WheeledVehicleMovementComponent4W.h"
#include "DrawDebugHelpers.h"

#include "AiCar.generated.h"

/**
 * 
 */
UCLASS()
class RACEAI_API AAiCar : public ARaceAIPawn
{
	GENERATED_BODY()
private:

	UPROPERTY()
	UAiCarAIController* controllerAI;
	
	bool isAIControlled = true;

	bool isDead = false;

	//arthur//
	float LastLogDuration = 0;
	const int sensorsCount = 5;
	const int sensorsAngle = 45;

	float SensorRayCast(FVector _castDir);
	//arthur//
protected:
	//arthur//
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName WallTag;
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLogActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bForceVisible;
	//arthur//
public:
	//arthur//
	UFUNCTION(BlueprintCallable)
	void OnWallCollision();
	bool IsCarDead();
	int* GetAllSensorsResult();

	void ResetVars();
	//arthur//

	virtual void BeginPlay() override;
	virtual void Tick(float Delta) override;
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UAiCarAIController* getAIController();
};
