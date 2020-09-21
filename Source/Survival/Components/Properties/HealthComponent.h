// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Survival/Components/Properties/PropertyComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UHealthComponent : public UPropertyComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UFUNCTION(BlueprintCallable)
	void AddHealth(float Heal);

	UFUNCTION(BlueprintCallable)
	void RemoveHealth(float Damage, AActor* Instigator);

	UFUNCTION(BlueprintCallable)
	float GetHealth();

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
