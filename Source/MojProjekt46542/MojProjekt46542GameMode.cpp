// Copyright Epic Games, Inc. All Rights Reserved.

#include "MojProjekt46542GameMode.h"
#include "MojProjekt46542PlayerController.h"
#include "MojProjekt46542Character.h"
#include "UObject/ConstructorHelpers.h"

AMojProjekt46542GameMode::AMojProjekt46542GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMojProjekt46542PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}