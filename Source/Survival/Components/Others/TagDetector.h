// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "TagDetector.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTagDetection ,AActor*, DetectedActor, FGameplayTagContainer, Tag);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UTagDetector : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTagDetector();

	void StartDetection();

	void StopDetection();

	UPROPERTY(BlueprintAssignable)
	FTagDetection OnActorWithTagDetected;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
	FGameplayTagContainer TagToDetect;

	UPROPERTY(EditDefaultsOnly)
	float DetectionRate;

	UPROPERTY(EditDefaultsOnly)
	float DetectionSphereRadius;

	UPROPERTY(EditDefaultsOnly)
	float DetectionLength;
	
	void DetectTag();

	TPair<FVector, FVector> GenerateDetectPosition();
	
	UWorld* World;

	class UCameraComponent* Camera;

	FTimerHandle TimerDetection;
		
};
