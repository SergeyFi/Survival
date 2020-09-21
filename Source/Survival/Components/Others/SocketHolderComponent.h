// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Survival/Structs/PlayerSlots.h"
#include "SocketHolderComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API USocketHolderComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USocketHolderComponent();

	TArray<EPlayerSlotName> GetSlots();

	FName GetSocket(EPlayerSlotName Slot);

private:

	UPROPERTY(EditDefaultsOnly)
	TMap<EPlayerSlotName, FName> SocketMap;
};
