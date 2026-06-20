// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/GameplayInterface.h"
#include "KeyItem.generated.h"

UCLASS()
class PGTEST_API AKeyItem : public AActor, public IGameplayInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AKeyItem();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(ReplicatedUsing=OnRep_KeyGrabbed, EditDefaultsOnly)
	bool bKeyGrabbed;
	
	UFUNCTION()
	void OnRep_KeyGrabbed();
	
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> KeyMesh;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Exec, Category="Interactable")
	void UpdateKey();
};
