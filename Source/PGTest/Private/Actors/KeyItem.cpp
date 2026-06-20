// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/KeyItem.h"

#include "Managers/MyGameInstance.h"
#include "Net/UnrealNetwork.h"


// Sets default values
AKeyItem::AKeyItem()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	
	KeyMesh = CreateDefaultSubobject<UStaticMeshComponent>("KeyMesh");
	KeyMesh->SetupAttachment(BaseMesh);
}

void AKeyItem::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AKeyItem, bKeyGrabbed);
}

void AKeyItem::OnRep_KeyGrabbed()
{
	UpdateKey();
}

void AKeyItem::Interact_Implementation(APawn* InstigatorPawn)
{
	IGameplayInterface::Interact_Implementation(InstigatorPawn);
	
	UMyGameInstance* MyGameInstance = Cast<UMyGameInstance>(GetGameInstance());
	if (!MyGameInstance) return;

	bKeyGrabbed = true;
	MyGameInstance->bHasDoorKey = bKeyGrabbed;

	UpdateKey();
	
	Destroy();
}

// Called when the game starts or when spawned
void AKeyItem::BeginPlay()
{
	Super::BeginPlay();
}

void AKeyItem::UpdateKey_Implementation()
{
	
}