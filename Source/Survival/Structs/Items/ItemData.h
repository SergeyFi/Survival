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

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UItemData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ItemCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ItemWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsStackable;

	UFUNCTION(BlueprintCallable)
	float GetWeight();

	UFUNCTION(BlueprintCallable)
	void AppendItem(UItemData* ItemData);
};
