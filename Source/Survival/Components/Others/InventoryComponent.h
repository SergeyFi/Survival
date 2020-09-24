// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Survival/Structs/Items/ItemData.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FItems
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	bool bIsStackable;

	UPROPERTY(EditDefaultsOnly)
	TArray<UItemData*> Items;
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

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FName, FItems> Inventory;
	
private:

    void AddNewItem(UItemData* ItemData);

	void AddExistingItem(UItemData* ItemData);
};
