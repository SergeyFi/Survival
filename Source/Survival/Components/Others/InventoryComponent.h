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


	bool AddItem(UItemData* ItemData);

	bool RemoveItem(FName ItemName, float Count, int32 ItemID);
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TMap<FName, FItems> Inventory;


private:

	UPROPERTY(EditDefaultsOnly)
	float MaxInventoryWeight;

	UPROPERTY(VisibleAnywhere)
	float CurrentInventoryWeight;

	int32 ID;

	bool CheckWeight(UItemData* ItemData);

	bool ItemExist(FName ItemName);

	void AddNewItem(UItemData* ItemData);

	void AppendExistingItem(UItemData* ItemData);

	int32 GetID();

	int32 GetIndexByID(int32 ItemID, TArray<FInventoryItem>& Items);

};
