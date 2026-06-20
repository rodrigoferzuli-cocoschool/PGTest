// Copyright Epic Games, Inc. All Rights Reserved.

#include "PGTestGameMode.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

APGTestGameMode::APGTestGameMode()
{
	// stub
}

void APGTestGameMode::CompleteMission(APawn* MyPawn)
{
	if (!HasAuthority()) return;
	
	if (!MyPawn) return;

	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if (!PlayerController) continue;

		APawn* Pawn = PlayerController->GetPawn();
		if (!Pawn) continue;

		Pawn->DisableInput(PlayerController);

		if (ACharacter* Character = Cast<ACharacter>(Pawn))
		{
			Character->GetCharacterMovement()->DisableMovement();
		}

		PlayerController->SetIgnoreMoveInput(true);
		PlayerController->SetIgnoreLookInput(true);
	}

	OnMissionComplete(MyPawn);
}