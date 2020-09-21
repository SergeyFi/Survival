// Fill out your copyright notice in the Description page of Project Settings.


#include "SocketHolderComponent.h"

// Sets default values for this component's properties
USocketHolderComponent::USocketHolderComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

FName USocketHolderComponent::GetPrimarySocketName()
{
	return PrimarySocketName;
}

FName USocketHolderComponent::GetStorageSocketName()
{
	return StorageSocketName;
}

void USocketHolderComponent::AttachToPrimarySocket(AActor* Target)
{
	AttachToSocket(PrimarySocketName, Target);
}

void USocketHolderComponent::AttachToStorageSocket(AActor* Target)
{
	AttachToSocket(StorageSocketName, Target);
}

void USocketHolderComponent::AttachToSocket(FName SocketName, AActor* Target)
{
	if (Target)
	{
		GetOwner()->AttachToActor(Target, FAttachmentTransformRules::SnapToTargetNotIncludingScale, SocketName);
	}
}
