// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"
#include "ItemPickupComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase="true") )
class SURVIVAL_API UItemPickupComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemPickupComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
	FComponentReference ComponentDetectorRef;

	class UComponentDetector* ComponentDetector;

	class UInventoryComponent* Inventory;

	void FindComponents();

	UFUNCTION()
	void OnActionBtnPressed();

	UFUNCTION(Server, Reliable)
	void AddItemToInventory(class UItemDataComponent* ItemData);

	virtual void AddItemToInventory_Implementation(class UItemDataComponent* ItemData);
		
};
