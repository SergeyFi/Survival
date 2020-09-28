// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Survival/Objects/ObjectReplicated.h"
#include "ObjectsRepComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UObjectsRepComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectsRepComponent();

	virtual bool ReplicateSubobjects (class UActorChannel *Channel, class FOutBunch *Bunch, FReplicationFlags *RepFlags) override;

	void GetLifetimeReplicatedProps (TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	TArray<UObjectReplicated*> ReplicatedObjects;

};
