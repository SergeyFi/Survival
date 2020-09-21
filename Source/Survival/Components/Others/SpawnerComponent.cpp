// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerComponent.h"

// Sets default values for this component's properties
USpawnerComponent::USpawnerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	SpawnRate = 0.1f;
}

void USpawnerComponent::StartSpawn()
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		GetWorld()->GetTimerManager().SetTimer(TimerSpawn, this, &USpawnerComponent::Spawn, SpawnRate, bIsLoop);
	}
}

void USpawnerComponent::StopSpawn()
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerSpawn);
	}
}

void USpawnerComponent::Spawn()
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		if (ActorToSpawn)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Instigator = GetOwner()->GetInstigator();
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
			auto SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, GetComponentTransform(), SpawnParams);

			OnActorSpawned.Broadcast(SpawnedActor);
		}
	}
}
