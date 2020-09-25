// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentDetector.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UComponentDetector::UComponentDetector()
{
	PrimaryComponentTick.bCanEverTick = false;

	DetectionRate = 0.1f;
}

void UComponentDetector::StartDetection()
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		if (World && Camera && ComponentToDetect)
		{
			World->GetTimerManager().SetTimer(TimerDetection, this, &UComponentDetector::DetectComponent, DetectionRate, true);
		}
	}
}

void UComponentDetector::StopDetection()
{
	if (World)
	{
		World->GetTimerManager().ClearTimer(TimerDetection);
	}
}

float UComponentDetector::GetDetectionRadius()
{
	return DetectionLength + DetectionSphereRadius;
}

const TArray<UActorComponent*> UComponentDetector::GetLastComponents()
{
	return LastComponents;
}

// Called when the game starts
void UComponentDetector::BeginPlay()
{
	Super::BeginPlay();

	Camera = GetOwner()->FindComponentByClass<UCameraComponent>();
	
	World = GetWorld();

	StartDetection();
}

TPair<FVector, FVector> UComponentDetector::GenerateDetectPosition()
{
	auto Start = Camera->GetComponentLocation();

	auto End = Camera->GetForwardVector() * DetectionLength + Start;

	return TPair<FVector, FVector>(Start, End);
}

void UComponentDetector::DetectComponent()
{
	TArray<FHitResult> HitResults;
	auto DetectPosition = GenerateDetectPosition();
	
	bool IsDetect = World->SweepMultiByChannel(HitResults, DetectPosition.Key, DetectPosition.Value, FQuat::Identity,
        ECollisionChannel::ECC_Visibility, FCollisionShape::MakeSphere(DetectionSphereRadius));

	if (IsDetect)
	{
		TArray<UActorComponent*> Components;
		
		for (auto& Hit : HitResults)
		{
			auto DetectedComponent = Hit.Actor->FindComponentByClass(ComponentToDetect);

			if (DetectedComponent)
			{
				if (DetectedComponent->GetOwner() != GetOwner())
				{
					Components.Add(DetectedComponent);
				}
			}
		}

		if (Components != LastComponents)
		{
			LastComponents = Components;
			OnComponentsDetected.Broadcast(Components);
		}
	}
}
