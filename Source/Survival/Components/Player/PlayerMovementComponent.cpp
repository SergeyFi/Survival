// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementComponent.h"
#include "Components/InputComponent.h"

// Sets default values for this component's properties
UPlayerMovementComponent::UPlayerMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UPlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	BindToInputComponent();
}

void UPlayerMovementComponent::BindToInputComponent()
{
	OwnerPawn = Cast<APawn>(GetOwner());

	if (OwnerPawn)
	{	
		InputComponent = OwnerPawn->FindComponentByClass<UInputComponent>();

		if (!InputComponent)
		{
			auto Controller = OwnerPawn->GetController();

			if (Controller)
			{
				InputComponent = OwnerPawn->GetController()->FindComponentByClass<UInputComponent>();
			}
		}

		if (InputComponent)
		{
			InputComponent->BindAxis("MoveForward", this, &UPlayerMovementComponent::MoveForward);
			InputComponent->BindAxis("MoveRight", this, &UPlayerMovementComponent::MoveRight);

			InputComponent->BindAxis("Turn", this, &UPlayerMovementComponent::Turn);
			InputComponent->BindAxis("LookUp", this, &UPlayerMovementComponent::LookUp);
		}
	}
}

void UPlayerMovementComponent::MoveForward(float Value)
{
	OwnerPawn->AddMovementInput(GetOwner()->GetActorForwardVector(), Value);
}

void UPlayerMovementComponent::MoveRight(float Value)
{
	OwnerPawn->AddMovementInput(GetOwner()->GetActorRightVector(), Value);
}

void UPlayerMovementComponent::Turn(float Value)
{
	OwnerPawn->AddControllerYawInput(Value);
}

void UPlayerMovementComponent::LookUp(float Value)
{
	OwnerPawn->AddControllerPitchInput(Value);
}

