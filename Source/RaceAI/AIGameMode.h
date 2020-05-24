// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AiCar.h"
#include "RaceAIHud.h"
#include "AiCarController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameSession.h"
#include "GameFramework/CheatManager.h"
#include "GameFramework/GameMode.h"
#include "AIGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RACEAI_API AAIGameMode : public AGameMode
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AAiCar*> IntantiatedCars;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AAiCarController* CarController;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int AiPawnsCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bForceGameRestart = false;

	float generationTime = 0;
	const float maxGenerationTime = 30; //In seconds

private:
	bool CheckIfAllCarsAreDead();
	void SpawnAiPawns(AAiCar* AiCar, AActor* StartSpot);
protected:
	void Tick(float DeltaSeconds) override;
	void RestartPlayer(AController* NewPlayer) override;
public:
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	//void RestartPlayerAtTransform(AController* NewPlayer, const FTransform& SpawnTransform) override;

	void nextGeneration();
};
