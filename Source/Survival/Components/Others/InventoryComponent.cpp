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
				AddExistingItem(ItemData);
			}
		}
	}
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UInventoryComponent::AddNewItem(UItemData* ItemData)
{
	TArray<UItemData*> Items{ItemData};

	FItems Datas{ItemData->bIsStackable, Items};
				
	Inventory.Add(ItemData->ItemName, Datas);
}

void UInventoryComponent::AddExistingItem(UItemData* ItemData)
{
	auto ItemsData = Inventory.Find(ItemData->ItemName);

	if (ItemsData->bIsStackable)
	{
		ItemsData->Items[0]->ItemCount += ItemData->ItemCount;
	}
	else
	{
		ItemsData->Items.Add(ItemData);
	}
}
