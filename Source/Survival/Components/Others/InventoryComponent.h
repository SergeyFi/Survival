// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Survival/Structs/Items/ItemData.h"
#include "InventoryComponent.generated.h"

USTRUCT()
struct FInventoryItem
{
	GENERATED_BODY()

	int32 ID;

	UPROPERTY()
	UItemData* Item;
};

USTRUCT()
struct FItems
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	bool bIsStackable;

	UPROPERTY(EditDefaultsOnly)
	TArray<FInventoryItem> InvItems;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UFUNCTION(BlueprintCallable)
	void AddItem(UItemData* ItemData);

	UFUNCTION(BlueprintCallable)
	UItemData* RemoveItem(FName ItemName, int32 ID, float Count);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TMap<FName, FItems> Inventory;
	
private:

	int32 CurrentID;

    void AddNewItem(UItemData* ItemData);

	void AppendExistingItem(UItemData* ItemData);

	int32 GetID();
};
