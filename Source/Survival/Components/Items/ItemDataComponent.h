// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Survival/Structs/Items/ItemData.h"
#include "ItemDataComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UItemDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemDataComponent();

	UFUNCTION(BlueprintCallable)
	UItemData* GetData();

private:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UItemData> ItemClass;

	UPROPERTY()
	UItemData* ItemData;
		
};
