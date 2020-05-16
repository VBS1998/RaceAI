// Copyright Epic Games, Inc. All Rights Reserved.

#include "RaceAIGameMode.h"
#include "RaceAIPawn.h"
#include "RaceAIHud.h"

ARaceAIGameMode::ARaceAIGameMode()
{
	DefaultPawnClass = ARaceAIPawn::StaticClass();
	HUDClass = ARaceAIHud::StaticClass();
}
