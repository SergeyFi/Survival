// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectsRepComponent.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "Engine/ActorChannel.h"

// Sets default values for this component's properties
UObjectsRepComponent::UObjectsRepComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UObjectsRepComponent::ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	bool WroteSomething = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);
	
	for (auto RepObj : ReplicatedObjects)
	{
		if (RepObj)
		{
			WroteSomething |= Channel->ReplicateSubobject(RepObj, *Bunch, *RepFlags);
		}
	}
	
	return WroteSomething;
}

void UObjectsRepComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UObjectsRepComponent, ReplicatedObjects);
}


// Called when the game starts
void UObjectsRepComponent::BeginPlay()
{
	Super::BeginPlay();
	
	SetIsReplicated(true);
}
