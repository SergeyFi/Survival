// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/ObjectMacros.h"

#include "PlayerSlots.generated.h"


UENUM(BlueprintType)
enum class EPlayerSlotName : uint8
{
	Primary			UMETA(DisplayName = "Primary"),
	BackLeft		UMETA(DisplayName = "BackLeft"),
	BackRight		UMETA(DisplayName = "BackRight"),
	LegLeft			UMETA(DisplayName = "LegLeft"),
	LegRight		UMETA(DisplayName = "LegRight")
 };


USTRUCT()
struct FPlayerSlot
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSet<EPlayerSlotName> SlotsNames;
};

UCLASS()
class SURVIVAL_API UPlayerSlots : public UObject
{
	GENERATED_BODY()
	
};
