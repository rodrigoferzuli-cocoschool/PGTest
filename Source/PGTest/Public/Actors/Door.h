// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/GameplayInterface.h"
#include "Door.generated.h"

UCLASS()
class PGTEST_API ADoor : public AActor, public IGameplayInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(EditAnywhere)
	float TargetYaw = 90.0f;
	
	UPROPERTY(EditDefaultsOnly)
	bool bDoorOpened;
	
	UFUNCTION(BlueprintCallable)
	float GetCurrentDoorYaw() const;
	
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> DoorMesh;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Exec, Category="Interactable")
	void UpdateDoor();
};
