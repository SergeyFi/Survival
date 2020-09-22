// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Survival/Structs/PlayerSlots.h"
#include "ItemHolder.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UItemHolder : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemHolder();

	UFUNCTION(BlueprintCallable)
	bool AddItem(class USocketHolderComponent* SocketHolder);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(class USocketHolderComponent* SocketHolder);

private:

	TMap<EPlayerSlotName, class USocketHolderComponent*> ItemSlots;

	bool AttachActor(FName SocketName, AActor* Target);
		
};
