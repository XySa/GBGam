// Copyright Epic Games, Inc. All Rights Reserved.

#include "GBGamGameMode.h"
#include "GBGamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGBGamGameMode::AGBGamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
