// Copyright Epic Games, Inc. All Rights Reserved.

#include "PGTestGameMode.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

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

	UpdateViewTargetCamera(MyPawn);
	OnMissionComplete(MyPawn);
}

void APGTestGameMode::UpdateViewTargetCamera(APawn* InPawn)
{
	if (InPawn == nullptr) return;

	if (SpectatorViewClass == nullptr) return;

	TArray<AActor*> ReturnedActors;
	UGameplayStatics::GetAllActorsOfClass(this, SpectatorViewClass, ReturnedActors);
	if (ReturnedActors.IsEmpty()) return;
	
	AActor* NewViewTarget = ReturnedActors[0];

	APlayerController* PlayerController = Cast<APlayerController>(InPawn->GetController());
	if (PlayerController == nullptr) return;

	if (NewViewTarget == nullptr) return;
	PlayerController->SetViewTargetWithBlend(NewViewTarget, BlendTime, VTBlend_Cubic);
}