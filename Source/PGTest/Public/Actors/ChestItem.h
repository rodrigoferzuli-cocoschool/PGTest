// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/GameplayInterface.h"
#include "ChestItem.generated.h"

UCLASS()
class PGTEST_API AChestItem : public AActor, public IGameplayInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChestItem();
	
	UPROPERTY(EditAnywhere)
	float TargetPitch = 120.0f;
	
	UPROPERTY(EditDefaultsOnly)
	bool bLidOpened;
	
	UFUNCTION(BlueprintCallable)
	float GetCurrentLidPitch() const;
	
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> LidMesh;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Exec, Category="Interactable")
	void UpdateLidChest();
};