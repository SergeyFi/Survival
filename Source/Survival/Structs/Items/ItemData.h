// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemData.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Item	UMETA(DisplayName = "Item")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase="true") )
class SURVIVAL_API UItemData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ItemCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ItemWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsStackable;

	UFUNCTION(BlueprintCallable)
	float GetWeight();

	UFUNCTION(BlueprintCallable)
	void AppendItem(UItemData* ItemData);

	UFUNCTION(BlueprintCallable)
	bool RemoveCount(float Count);
};
