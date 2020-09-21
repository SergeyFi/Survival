// Fill out your copyright notice in the Description page of Project Settings.


#include "SocketHolderComponent.h"

// Sets default values for this component's properties
USocketHolderComponent::USocketHolderComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

TArray<EPlayerSlotName> USocketHolderComponent::GetSlots()
{
	TArray<EPlayerSlotName> Slots;
	SocketMap.GetKeys(Slots);
	
	return Slots;
}

FName USocketHolderComponent::GetSocket(EPlayerSlotName Slot)
{
	return SocketMap.FindChecked(Slot);
}
