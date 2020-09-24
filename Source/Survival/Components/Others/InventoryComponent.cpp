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
			if (!Inventory.Contains(ItemData->ItemName))
			{
				AddNewItem(ItemData);
			}
			else
			{   
				AppendExistingItem(ItemData);
			}
		}
	}
}

UItemData* UInventoryComponent::RemoveItem(FName ItemName, int32 ID, float Count)
{
	UItemData* Item = nullptr;
	
	if (Inventory.Contains(ItemName))
	{
		auto Items = Inventory.Find(ItemName);

		int ItemID = -1;
		for (auto i = 0; i < Items->InvItems.Num(); ++i)
		{
			if (Items->InvItems[i].ID == ID)
			{
				ItemID = i;
				Item = Items->InvItems[i].Item;
				break;
			}
		}

		if (ItemID >= 0)
		{
			Items->InvItems.RemoveAt(ItemID);
		}
	}

	return Item;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UInventoryComponent::AddNewItem(UItemData* ItemData)
{
	FInventoryItem InvItem{GetID(), ItemData};
	
	TArray<FInventoryItem> Items{InvItem};

	FItems Datas{ItemData->bIsStackable, Items};
				
	Inventory.Add(ItemData->ItemName, Datas);
}

void UInventoryComponent::AppendExistingItem(UItemData* ItemData)
{
	auto ItemsData = Inventory.Find(ItemData->ItemName);

	if (ItemsData->bIsStackable)
	{
		ItemsData->InvItems[0].Item->ItemCount += ItemData->ItemCount;
	}
	else
	{
		ItemsData->InvItems.Add({GetID(), ItemData});
	}
}

int UInventoryComponent::GetID()
{
	++CurrentID;
	
	return CurrentID;
}
