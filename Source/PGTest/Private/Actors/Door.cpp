// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Actors/Door.h"


// Sets default values
ADoor::ADoor()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	DoorMesh->SetupAttachment(BaseMesh);
}

float ADoor::GetCurrentDoorYaw() const
{
	return bDoorOpened ? TargetYaw : 0.0f;
}

void ADoor::Interact_Implementation(APawn* InstigatorPawn)
{
	IGameplayInterface::Interact_Implementation(InstigatorPawn);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
}

void ADoor::UpdateDoor_Implementation()
{
	bDoorOpened = !bDoorOpened;
}

