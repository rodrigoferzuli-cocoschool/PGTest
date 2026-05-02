// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Actors/WallLever.h"

#include "Interfaces/GameplayInterface.h"


// Sets default values
AWallLever::AWallLever()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	
	LeverMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeverMesh");
	LeverMesh->SetupAttachment(BaseMesh);
}

float AWallLever::GetCurrentLeverPitch() const
{
	return bLeverOn ? TargetPitch : 140.0f;
}

void AWallLever::Interact_Implementation(APawn* InstigatorPawn)
{
	IGameplayInterface::Interact_Implementation(InstigatorPawn);
}

// Called when the game starts or when spawned
void AWallLever::BeginPlay()
{
	Super::BeginPlay();
}

void AWallLever::UpdateLever_Implementation()
{
	bLeverOn = !bLeverOn;
}
