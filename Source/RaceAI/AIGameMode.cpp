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

	generationTime += DeltaSeconds;

	if (CheckIfAllCarsAreDead() || generationTime > maxGenerationTime) nextGeneration();
}
bool AAIGameMode::CheckIfAllCarsAreDead()
{
	if (bForceGameRestart) return true;

	for (int i = 0; i < IntantiatedCars.Num(); i++)
	{
		if (!IntantiatedCars[i]->IsCarDead()) return false;
	}

	return true;
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
	IntantiatedCars[0]->SetFolderPath("/AiCars/Pawns");
	SpawnAiPawns(IntantiatedCars[0], FindPlayerStart(NewPlayer));
}
void AAIGameMode::SpawnAiPawns(AAiCar* AiCar, AActor* StartSpot)
{
	//UE_LOG(LogTemp, Log, TEXT("SpawnActor failed because the spawned actor %s IsPendingKill"));
	FActorSpawnParameters spawnInfo;
	FRotator startRotation(ForceInit);
	startRotation.Yaw = StartSpot->GetActorRotation().Yaw;
	FVector startLocation = StartSpot->GetActorLocation();
	FTransform transform = FTransform(startRotation, startLocation);
	UWorld* world = GetWorld();
	FString folderName;

	spawnInfo.Instigator = GetInstigator();
	spawnInfo.ObjectFlags |= RF_Transient;
	
	

	for (int i = 1; i < AiPawnsCount; i++)
	{
		folderName = "/AiCars/CarNumber_";
		folderName.AppendInt(i);

		AAiCar* InstantiatedAiCar = world->SpawnActor<AAiCar>(AiCar->GetClass(), transform, spawnInfo);
		if (!InstantiatedAiCar)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Deu ruim na hora de instanciar um ai"));
		}
		InstantiatedAiCar->SetFolderPath((FName)folderName);
		InstantiatedAiCar->SpawnDefaultController();
		InstantiatedAiCar->GetController()->SetFolderPath((FName)folderName);
		IntantiatedCars.Add(InstantiatedAiCar);
	}
}

void AAIGameMode::nextGeneration()
{
	int maxFitness = 0;
	UNeuralNetwork* bestNetwork = nullptr;
	int bestCar_num = 0;
	FHitResult outHit;

	for (int i = 0; i < IntantiatedCars.Num(); i++)
	{
		FVector carPosition = IntantiatedCars[i]->GetActorLocation();
		FVector2D carPosition2D = FVector2D(carPosition.X, carPosition.Y);
		int thisFitness = UAiCarAIController::fitness(carPosition2D, FVector2D(0, 0));
		if (thisFitness > maxFitness) {
			bestNetwork = IntantiatedCars[i]->getAIController()->getNetwork();
			maxFitness = thisFitness;
			bestCar_num = i;
		}
	}

	for (int i = 0; i < IntantiatedCars.Num(); i++) {
		if (i != bestCar_num) {
			UAiCarAIController* controller = IntantiatedCars[i]->getAIController();
			controller->deleteNetwork();
			controller->setNetwork(bestNetwork->mutateNetwork());
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Chamou reset"));
	for (int i = 0; i < IntantiatedCars.Num(); i++) {
		IntantiatedCars[i]->SetActorLocationAndRotation(FindPlayerStart(IntantiatedCars[i]->GetController())->GetActorLocation(), FindPlayerStart(IntantiatedCars[i]->GetController())->GetActorRotation(), false, &outHit, ETeleportType::ResetPhysics);
	}
	generationTime = 0;
}