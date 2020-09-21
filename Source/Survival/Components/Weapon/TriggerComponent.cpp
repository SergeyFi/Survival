// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"
#include "Survival/Components/Others/SpawnerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UTriggerComponent::Fire()
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		for (auto Spawner : SpawnerComponents)
		{
			if (Spawner)
			{
				Spawner->StartSpawn();
			}
		}
	}
}

void UTriggerComponent::FireStop()
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		for (auto Spawner : SpawnerComponents)
		{
			if (Spawner)
			{
				Spawner->StopSpawn();
			}
		}
	}
}


// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwnerRole() == ROLE_Authority)
	{
		BindToSpawners();
	}
}

void UTriggerComponent::BindToSpawners()
{
	GetOwner()->GetComponents(SpawnerComponents);
}
