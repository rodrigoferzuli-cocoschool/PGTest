// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/GameplayInterface.h"
#include "WallLever.generated.h"

UCLASS()
class PGTEST_API AWallLever : public AActor, public IGameplayInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWallLever();

	UPROPERTY(EditAnywhere)
	float TargetPitch = 20.0f;
	
	UPROPERTY(EditDefaultsOnly)
	bool bLeverOn;
	
	UFUNCTION(BlueprintCallable)
	float GetCurrentLeverPitch() const;
	
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> LeverMesh;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Exec, Category="Interactable")
	void UpdateLever();
};
