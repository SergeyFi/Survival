// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::AddItem(UItemData* ItemData)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		if (ItemData)
		{
			if (CheckWeight(ItemData))
			{
				if (!ItemData->bIsStackable)
				{
					ReplicatedObjects.Add(ItemData);
				}
			}
		}
	}
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

TArray<UItemData*> UInventoryComponent::GetItemsData()
{
	TArray<UItemData*> Datas;

	for (auto RepObject : ReplicatedObjects)
	{
		Datas.Add(Cast<UItemData>(RepObject));
	}

	return Datas;
}

UItemData* UInventoryComponent::GetItem(FName ItemName)
{
	for (auto Item : GetItemsData())
	{
		if (Item->ItemName == ItemName)
		{
			return Item;
		}
	}

	return nullptr;
}

bool UInventoryComponent::CheckWeight(UItemData* ItemData)
{
	return ItemData->GetWeight() + CurrentWeight <= MaxWeight;
}
