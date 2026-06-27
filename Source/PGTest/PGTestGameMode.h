// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PGTestGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class APGTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	APGTestGameMode();
	
	void CompleteMission(APawn* MyPawn);
	
	UFUNCTION(BlueprintImplementableEvent, Category="GameMode")
	void OnMissionComplete(APawn* MyPawn);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category="GameMode")
	TSubclassOf<AActor> SpectatorViewClass;

	float BlendTime = 3.0f;
	
	void UpdateViewTargetCamera(APawn* InPawn);
};