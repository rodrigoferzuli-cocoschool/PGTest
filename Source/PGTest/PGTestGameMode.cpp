// Copyright Epic Games, Inc. All Rights Reserved.

#include "PGTestGameMode.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Managers/MyGameStateBase.h"

APGTestGameMode::APGTestGameMode()
{
	// stub
}

void APGTestGameMode::CompleteMission(APawn* MyPawn)
{
	if (MyPawn == nullptr) return;
   
	//MyPawn->DisableInput(nullptr);
	
	UpdateViewTargetCamera(MyPawn);
	
	AMyGameStateBase* GS = GetGameState<AMyGameStateBase>();
	if (GS != nullptr)
	{
		GS->Multicast_OnMissionComplete(MyPawn);
	}

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
	if (NewViewTarget == nullptr) return;

	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		APlayerController* PC = It->Get();
		if (PC == nullptr) return;
		
		PC->SetViewTargetWithBlend(NewViewTarget, BlendTime, VTBlend_Cubic);
	}
}