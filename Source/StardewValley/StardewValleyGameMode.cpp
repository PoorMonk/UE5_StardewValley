// Copyright Epic Games, Inc. All Rights Reserved.

#include "StardewValleyGameMode.h"
#include "StardewValleyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStardewValleyGameMode::AStardewValleyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
