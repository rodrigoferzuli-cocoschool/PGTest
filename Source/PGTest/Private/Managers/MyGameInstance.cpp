// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();
	
	bHasDoorKey = false;
}

UMyGameInstance* UMyGameInstance::Get()
{
	if (!GEngine)
	{
		return nullptr;
	}

	const FWorldContext* WorldContext = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
	if (!WorldContext || !WorldContext->World())
	{
		return nullptr;
	}

	return Cast<UMyGameInstance>(WorldContext->World()->GetGameInstance());
}
