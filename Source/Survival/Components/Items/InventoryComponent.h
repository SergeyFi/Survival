// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Survival/Structs/Items/ItemData.h"
#include "Survival/Components/Items/ItemDataComponent.h"
#include "Survival/Components/Others/ObjectsRepComponent.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	bool bIsStackable;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UItemData* Item;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase="true") )
class SURVIVAL_API UInventoryComponent : public UObjectsRepComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	void AddItem(UItemDataComponent* ItemDataComponent);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float MaxWeight;

	UPROPERTY(EditDefaultsOnly)
	float CurrentWeight;

private:

	TArray<class UItemData*> GetItemsData();

	UItemData* GetItem(FName ItemName);

	bool CheckWeight(UItemData* ItemData);
};
