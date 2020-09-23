// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "TagComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UTagComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTagComponent();

	UFUNCTION(BlueprintCallable)
	FGameplayTagContainer GetTags();

protected:

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer Tags;
		
};
