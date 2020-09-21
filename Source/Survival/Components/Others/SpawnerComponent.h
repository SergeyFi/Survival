// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpawnerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpawnDelegate, AActor*, SpawnedActor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API USpawnerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnerComponent();

	UFUNCTION(BlueprintCallable)
	void StartSpawn();

	UFUNCTION(BlueprintCallable)
	void StopSpawn();

	FSpawnDelegate OnActorSpawned;
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere)
	bool bIsLoop;

	UPROPERTY(EditAnywhere)
	float SpawnRate;

	FTimerHandle TimerSpawn;

	void Spawn();
		
};
