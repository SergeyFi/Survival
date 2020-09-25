// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemDataComponent.h"

// Sets default values for this component's properties
UItemDataComponent::UItemDataComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	ItemData = NewObject<UItemData>(ItemClass);

}

UItemData* UItemDataComponent::GetData()
{
	return ItemData;
}
