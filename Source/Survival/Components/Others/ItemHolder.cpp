// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemHolder.h"
#include "Survival/Components/Others/SocketHolderComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values for this component's properties
UItemHolder::UItemHolder()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UItemHolder::AddItem(USocketHolderComponent* SocketHolder)
{
	if (SocketHolder)
	{
		for (const auto& Slot : SocketHolder->GetSlots())
		{
			if (!ItemSlots.Contains(Slot))
			{
				if (AttachActor(SocketHolder->GetSocket(Slot), SocketHolder->GetOwner()))
				{
					ItemSlots.Add(Slot, SocketHolder);

					return true;
				}
			}
		}
	}

	return false;
}

void UItemHolder::RemoveItem(USocketHolderComponent* SocketHolder)
{
	
}

bool UItemHolder::AttachActor(FName SocketName, AActor* Target)
{
	if (Target)
	{
		auto SkeletalMesh = GetOwner()->FindComponentByClass<USkeletalMeshComponent>();

		if (SkeletalMesh)
		{
			if (SkeletalMesh->DoesSocketExist(SocketName))
			{
				Target->AttachToComponent(SkeletalMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale, SocketName);

				return true;
			}
		}
	}

	return false;
}

