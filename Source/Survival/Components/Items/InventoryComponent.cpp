// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UInventoryComponent::AddItem(UItemData* ItemData)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		if (ItemData)
		{
			if (CheckWeight(ItemData))
			{
				if (!ItemExist(ItemData->ItemName))
				{
					AddNewItem(ItemData);
				}
				else
				{
					AppendExistingItem(ItemData);
				}

				return true;
			}
		}
	}

	return false;
}

bool UInventoryComponent::RemoveItem(FName ItemName, float Count, int32 ItemID)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		if (ItemExist(ItemName))
		{
			auto& Items = Inventory.Find(ItemName)->InvItems;

			auto Index = GetIndexByID(ItemID, Items);

			if (!Items[Index].Item->RemoveCount(Count))
			{
				Items.RemoveAt(Index);
			}
		}
	}
	
	return false;
}

TArray<FInventoryItem> UInventoryComponent::GetItemsList()
{
	TArray<FInventoryItem> ItemsList;

	for (auto& Items : Inventory)
	{
		for (auto Item : Items.Value.InvItems)
		{
			ItemsList.Add(Item);
		}
	}

	return ItemsList;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

bool UInventoryComponent::CheckWeight(UItemData* ItemData)
{
	return ItemData->GetWeight() + CurrentInventoryWeight <= MaxInventoryWeight;
}

bool UInventoryComponent::ItemExist(FName ItemName)
{
	return Inventory.Contains(ItemName);
}

void UInventoryComponent::AddNewItem(UItemData* ItemData)
{
	FInventoryItem ItemNew {GetID(), ItemData};

	TArray<FInventoryItem> InvItemsNew{ItemNew};

	Inventory.Add(ItemData->ItemName, {ItemData->bIsStackable, InvItemsNew});
}

void UInventoryComponent::AppendExistingItem(UItemData* ItemData)
{
	auto ItemsExisting = Inventory.Find(ItemData->ItemName);

	if (ItemsExisting->bIsStackable)
	{
		ItemsExisting->InvItems[0].Item->AppendItem(ItemData);
	}
	else
	{
		ItemsExisting->InvItems.Add({GetID(), ItemData});
	}
}

int32 UInventoryComponent::GetID()
{
	++ID;

	return ID;
}

int32 UInventoryComponent::GetIndexByID(int32 ItemID, TArray<FInventoryItem>& Items)
{
	for (auto i = 0; i < Items.Num(); ++i)
	{
		if (Items[i].ID == ItemID)
		{
			return i;
		}
	}

	return 0;
}

