// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIGameMode.h"
#include "AiCar.h"
#include "AiGameState.h"
#include "RaceAIHud.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameSession.h"
#include "GameFramework/CheatManager.h"
#include "GameFramework/GameModeBase.h"
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
	int AiPawnsCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bForceGameRestart = false;

private:
	bool CheckIfAllCarsAreDead();
	void SpawnAiPawns(AAiCar* AiCar, AActor* StartSpot);
protected:
	void Tick(float DeltaSeconds) override;
	void RestartPlayer(AController* NewPlayer) override;
public:
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	//void RestartPlayerAtTransform(AController* NewPlayer, const FTransform& SpawnTransform) override;
};
