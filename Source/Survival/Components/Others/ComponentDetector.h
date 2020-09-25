// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComponentDetector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComponentDetection, UActorComponent*, DetectedComponent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UComponentDetector : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComponentDetector();

	UFUNCTION(BlueprintCallable)
	void StartDetection();

	UFUNCTION(BlueprintCallable)
	void StopDetection();

	UFUNCTION(BlueprintCallable)
	float GetDetectionRadius();

	UPROPERTY(BlueprintAssignable)
	FComponentDetection OnComponentDetected;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
	float DetectionRate;

	UPROPERTY(EditDefaultsOnly)
	float DetectionSphereRadius;

	UPROPERTY(EditDefaultsOnly)
	float DetectionLength;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UActorComponent> ComponentToDetect;

	TPair<FVector, FVector> GenerateDetectPosition();
	
	UWorld* World;

	class UCameraComponent* Camera;

	FTimerHandle TimerDetection;

	void DetectComponent();
		
};
