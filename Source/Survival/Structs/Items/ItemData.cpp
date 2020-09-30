// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemData.h"
#include "Net/UnrealNetwork.h"

void UItemData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UItemData, ItemCount);
}

void UItemData::AppendItem(UItemData* ItemData)
{
    ItemCount += ItemData->ItemCount;
    ItemData->ItemCount = 0.0f;

    auto RemainingItem = StackSize - ItemCount;

    if (RemainingItem <= 0.0f)
    {
        ItemData->ItemCount -= RemainingItem;
    }

    UpdateWeight();
}

void UItemData::UpdateWeight()
{
    ItemWeight = ItemCount * ItemUnitWeight;
}
