// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemData.h"
#include "Net/UnrealNetwork.h"

void UItemData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UItemData, ItemCount);
}

float UItemData::GetWeight()
{
    return ItemCount * ItemWeight;
}

void UItemData::AppendItem(UItemData* ItemData)
{
    ItemCount += ItemData->ItemCount;
    ItemWeight += ItemData->GetWeight();
}

bool UItemData::RemoveCount(float Count)
{
    ItemCount -= Count;

    if (ItemCount <= 0.0f)
    {
        return false;
    }

    return true;
}
