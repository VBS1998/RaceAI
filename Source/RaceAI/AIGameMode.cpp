// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGameMode.h"

//void AAIGameMode::RestartPlayerAtTransform(AController* NewPlayer, const FTransform& SpawnTransform)
//{
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
//	Super::RestartPlayerAtTransform(NewPlayer, SpawnTransform);
//}

void AAIGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}
void AAIGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (CheckIfAllCarsAreDead()) RestartGame();
}
bool AAIGameMode::CheckIfAllCarsAreDead()
{
	bool allCarsAreDead = true;

	if (bForceGameRestart) return true;

	for (int i = 0; i < IntantiatedCars.Num(); i++)
	{
		if (!IntantiatedCars[i]->IsCarDead()) allCarsAreDead = false;
	}

	return allCarsAreDead;
}
void AAIGameMode::RestartPlayer(AController* NewPlayer)
{
	if (NewPlayer == nullptr || NewPlayer->IsPendingKillPending())
	{
		return;
	}
	
	AActor* StartSpot = FindPlayerStart(NewPlayer);

	// If a start spot wasn't found,
	if (StartSpot == nullptr)
	{
		// Check for a previously assigned spot
		if (NewPlayer->StartSpot != nullptr)
		{
			StartSpot = NewPlayer->StartSpot.Get();
			UE_LOG(LogGameMode, Warning, TEXT("RestartPlayer: Player start not found, using last start spot"));
		}
	}
	
	RestartPlayerAtPlayerStart(NewPlayer, StartSpot);

	IntantiatedCars.Add((AAiCar*)NewPlayer->GetPawn());
	SpawnAiPawns(IntantiatedCars[0], FindPlayerStart(NewPlayer));
}
void AAIGameMode::SpawnAiPawns(AAiCar* AiCar, AActor* StartSpot)
{
	UE_LOG(LogTemp, Log, TEXT("SpawnActor failed because the spawned actor %s IsPendingKill"));

	FActorSpawnParameters SpawnInfo;
	FRotator StartRotation(ForceInit);
	StartRotation.Yaw = StartSpot->GetActorRotation().Yaw;
	FVector StartLocation = StartSpot->GetActorLocation();
	FTransform Transform = FTransform(StartRotation, StartLocation);
	UWorld* world = GetWorld();

	SpawnInfo.Instigator = GetInstigator();
	SpawnInfo.ObjectFlags |= RF_Transient;	

	for (int i = 0; i < AiPawnsCount; i++)
	{
		AAiCar* InstantiatedAiCar = world->SpawnActor<AAiCar>(AiCar->GetClass(), Transform, SpawnInfo);
		if (!InstantiatedAiCar)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Deu ruim na hora de instanciar um ai"));
		}
		IntantiatedCars.Add(InstantiatedAiCar);
	}
}