// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Survival/Components/Others/ObjectsRepComponent.h"
#include "Survival/Structs/Items/ItemData.h"
#include "ItemDataComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UItemDataComponent : public UObjectsRepComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemDataComponent();

	UFUNCTION(BlueprintCallable)
	UItemData* GetData();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UItemData> ItemClass;
		
};
