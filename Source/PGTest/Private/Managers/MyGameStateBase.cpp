// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/MyGameStateBase.h"

void AMyGameStateBase::Multicast_OnMissionComplete_Implementation(APawn* InPawn)
{
	if (InPawn == nullptr) return;

	if (APlayerController* MyPlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (APawn* MyPawn = MyPlayerController->GetPawn())
		{
			MyPawn->DisableInput(nullptr);
		}
	}
}