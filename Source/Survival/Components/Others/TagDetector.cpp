// Fill out your copyright notice in the Description page of Project Settings.


#include "TagDetector.h"
#include "Camera/CameraComponent.h"
#include "Survival/Components/Others/TagComponent.h"

// Sets default values for this component's properties
UTagDetector::UTagDetector()
{
	PrimaryComponentTick.bCanEverTick = true;

	DetectionRate = 0.1f;

}

void UTagDetector::StartDetection()
{
	if (World && Camera)
	{
		World->GetTimerManager().SetTimer(TimerDetection, this, &UTagDetector::DetectTag, DetectionRate, true);
	}
}

void UTagDetector::StopDetection()
{
	if (World)
	{
		World->GetTimerManager().ClearTimer(TimerDetection);
	}
}


// Called when the game starts
void UTagDetector::BeginPlay()
{
	Super::BeginPlay();

	Camera = GetOwner()->FindComponentByClass<UCameraComponent>();
	
	World = GetWorld();

	StartDetection();
}

void UTagDetector::DetectTag()
{
	TArray<FHitResult> HitResults;
	auto DetectPosition = GenerateDetectPosition();
	
	bool IsDetect = World->SweepMultiByChannel(HitResults, DetectPosition.Key, DetectPosition.Value, FQuat::Identity,
		ECollisionChannel::ECC_Visibility, FCollisionShape::MakeSphere(DetectionSphereRadius));

	if (IsDetect)
	{
		for (auto& Hit : HitResults)
		{
			auto TagComponent = Hit.Actor->FindComponentByClass<UTagComponent>();

			if (TagComponent)
			{
				if (TagComponent->GetTags().HasAny(TagToDetect))
				{
					OnActorWithTagDetected.Broadcast(Hit.Actor.Get(), TagComponent->GetTags());
				}
			}
		}
	}
}

TPair<FVector, FVector> UTagDetector::GenerateDetectPosition()
{
	auto Start = Camera->GetComponentLocation();

	auto End = Camera->GetForwardVector() * DetectionLength + Start;

	return TPair<FVector, FVector>(Start, End);
}
