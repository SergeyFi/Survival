// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PropertyComponent.generated.h"


UCLASS( ClassGroup=(Custom))
class SURVIVAL_API UPropertyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPropertyComponent();

protected:

	virtual void BeginPlay() override;

	void AddValue(float AddValue);

    void RemoveValue(float RemoveValue);

    float GetValue();

	UPROPERTY(EditDefaultsOnly, Replicated)
	float Value;

	UPROPERTY(EditDefaultsOnly)
	float MinValue;

	UPROPERTY(EditDefaultsOnly)
	float MaxValue;

	void CheckValueLimits();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		
};
