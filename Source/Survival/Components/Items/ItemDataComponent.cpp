// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDataComponent.h"

// Sets default values for this component's properties
UItemDataComponent::UItemDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UItemDataComponent::BeginPlay()
{
	Super::BeginPlay();

	if (ItemClass && GetOwnerRole() == ROLE_Authority)
	{
		ReplicatedObjects.Add(NewObject<UItemData>(this, ItemClass));
	}
}

UItemData* UItemDataComponent::GetData()
{
	if (ReplicatedObjects.Num() > 0)
	{
		return  Cast<UItemData>(ReplicatedObjects[0]);
	}
	
	return nullptr;
}
