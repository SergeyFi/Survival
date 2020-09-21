// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UHealthComponent::AddHealth(float Heal)
{
	AddValue(Heal);
}

void UHealthComponent::RemoveHealth(float Damage, AActor* Instigator)
{
	RemoveValue(Damage);
}

float UHealthComponent::GetHealth()
{
	return Value;
}

float UHealthComponent::GetMaxHealth()
{
	return MaxValue;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

}
