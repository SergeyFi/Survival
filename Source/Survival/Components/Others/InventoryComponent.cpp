// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include "IDetailTreeNode.h"

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
				if (!ItemExist(ItemData))
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

	return false;
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

bool UInventoryComponent::ItemExist(UItemData* ItemData)
{
	return Inventory.Contains(ItemData->ItemName);
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

