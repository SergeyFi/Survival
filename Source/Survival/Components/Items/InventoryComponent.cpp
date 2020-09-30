// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Survival/Components/Items/ItemDataComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	MaxWeight = 30.0f;
}

void UInventoryComponent::AddItem(UItemDataComponent* ItemDataComponent)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		if (ItemDataComponent)
		{
			auto ItemData = ItemDataComponent->GetData();
			
			if (ItemData)
			{
				if (AddWeight(ItemData))
				{	
					auto ExistingItem = GetItem(ItemData->ItemName);
					
					if (!ItemData->bIsStackable || ItemData->bIsStackable && ExistingItem == nullptr)
					{
						AddItem(ItemData);
					}
					else
					{
						ExistingItem->AppendItem(ItemData);

						if (ItemData->ItemCount > 0)
						{
							AddItem(ItemData);
						}
					}

					ItemDataComponent->GetOwner()->Destroy();
				}
			}
		}
	}
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	SetIsReplicated(true);
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

bool UInventoryComponent::AddWeight(UItemData* ItemData)
{
	if (ItemData->ItemWeight + CurrentWeight <= MaxWeight)
	{
		CurrentWeight += ItemData->ItemWeight;

		return true;
	}
	
	return false;
}

void UInventoryComponent::AddItem(UItemData* ItemData)
{
	ReplicatedObjects.Add(ItemData);
}
