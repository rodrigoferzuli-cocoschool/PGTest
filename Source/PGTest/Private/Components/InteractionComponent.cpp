// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InteractionComponent.h"
#include "KismetTraceUtils.h"
#include "Interfaces/GameplayInterface.h"


// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr) return;
	
	FVector EyeLocation;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
	
	FVector End = EyeLocation + EyeRotation.Vector() * 1200;
	FHitResult Hit;
	
	bool bBlockingHit = GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);
	
	AActor* HitActor = Hit.GetActor();
	if (HitActor)
	{
		if (HitActor->Implements<UGameplayInterface>())
		{
			APawn* MyPawn = Cast<APawn>(MyOwner);
			if (MyPawn)
			{
				IGameplayInterface::Execute_Interact(HitActor, MyPawn);
			}
		}
	}
	
	if (bShowDebug)
	{
		FColor LineColor = bBlockingHit ? FColor::Green : FColor::Red;
		DrawDebugLine(GetWorld(), EyeLocation, End, LineColor, false, 3.0f, 0, 2.0f);
	}
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

