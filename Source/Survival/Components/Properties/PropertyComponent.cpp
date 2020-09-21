// Fill out your copyright notice in the Description page of Project Settings.


#include "PropertyComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UPropertyComponent::UPropertyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicated(true);

	MaxValue = 100.0f;
	Value = MaxValue;

}

void UPropertyComponent::AddValue(float AddValue)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		Value += AddValue;

		CheckValueLimits();
	}
}

void UPropertyComponent::RemoveValue(float RemoveValue)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		Value -= RemoveValue;

		CheckValueLimits();
	}
}

float UPropertyComponent::GetValue()
{
	return Value;
}

void UPropertyComponent::CheckValueLimits()
{
	if (Value > MaxValue)
	{
		Value = MaxValue;
	}

	if (Value < MinValue)
	{
		Value = MinValue;
	}
}

void UPropertyComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UPropertyComponent, Value);
}
