// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SocketHolderComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API USocketHolderComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USocketHolderComponent();

	UFUNCTION(BlueprintCallable)
	FName GetPrimarySocketName();

	UFUNCTION(BlueprintCallable)
	FName GetStorageSocketName();

	UFUNCTION(BlueprintCallable)
	void AttachToPrimarySocket(AActor* Target);

	UFUNCTION(BlueprintCallable)
	void AttachToStorageSocket(AActor* Target);

private:

	UPROPERTY(EditDefaultsOnly)
	FName PrimarySocketName;

	UPROPERTY(EditDefaultsOnly)
	FName StorageSocketName;

	void AttachToSocket(FName SocketName, AActor* Target);
};
