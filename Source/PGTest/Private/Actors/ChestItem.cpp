// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Actors/ChestItem.h"


// Sets default values
AChestItem::AChestItem()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	
	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);
}

float AChestItem::GetCurrentLidPitch() const
{
	return bLidOpened ? TargetPitch : 0.0f;
}

void AChestItem::Interact_Implementation(APawn* InstigatorPawn)
{
	IGameplayInterface::Interact_Implementation(InstigatorPawn);
}

// Called when the game starts or when spawned
void AChestItem::BeginPlay()
{
	Super::BeginPlay();
}

void AChestItem::UpdateLidChest_Implementation()
{
	bLidOpened = !bLidOpened;
}