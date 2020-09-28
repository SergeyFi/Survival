// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPickupComponent.h"

#include "ItemDataComponent.h"
#include "Survival/Components/Others/ComponentDetector.h"
#include "Survival/Components/Player/ActiontInputComponent.h"
#include "Survival/Components/Items/InventoryComponent.h"
#include "Survival/Components/Items/ItemDataComponent.h"

// Sets default values for this component's properties
UItemPickupComponent::UItemPickupComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UItemPickupComponent::BeginPlay()
{
	Super::BeginPlay();

	FindComponents();
}

void UItemPickupComponent::FindComponents()
{
	if (GetOwnerRole() != ROLE_Authority)
	{
		ComponentDetector = Cast<UComponentDetector>(ComponentDetectorRef.GetComponent(GetOwner()));

		auto ActionComponent = GetOwner()->FindComponentByClass<UActiontInputComponent>();

		if (ActionComponent)
		{
			ActionComponent->OnInteractPressedEvent.AddDynamic(this, &UItemPickupComponent::OnActionBtnPressed);
		}
	}

	Inventory = GetOwner()->FindComponentByClass<UInventoryComponent>();
}

void UItemPickupComponent::OnActionBtnPressed()
{
	if (ComponentDetector->GetLastComponents().Num() > 0)
	{
		auto ItemDataComponent = Cast<UItemDataComponent>(ComponentDetector->GetLastComponents()[0]);
		
		AddItemToInventory(ItemDataComponent);
	}
}

void UItemPickupComponent::AddItemToInventory_Implementation(class UItemDataComponent* ItemData)
{
	if (Inventory)
	{
		Inventory->AddItem(ItemData);
	}
}
