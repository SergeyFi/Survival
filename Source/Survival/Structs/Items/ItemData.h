// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Survival/Objects/ObjectReplicated.h"
#include "ItemData.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Item	UMETA(DisplayName = "Item")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, IsBlueprintBase="true") )
class SURVIVAL_API UItemData : public UObjectReplicated
{
	GENERATED_BODY()

public:

	void GetLifetimeReplicatedProps (TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ItemName;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly)
	float ItemCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float StackSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ItemUnitWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ItemWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bIsStackable;

	UFUNCTION(BlueprintCallable)
	void AppendItem(UItemData* ItemData);

private:

	void UpdateWeight();
};
