// Fill out your copyright notice in the Description page of Project Settings.


#include "ActiontInputComponent.h"

// Sets default values for this component's properties
UActiontInputComponent::UActiontInputComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UActiontInputComponent::BeginPlay()
{
	Super::BeginPlay();

	BindToInput();
}

void UActiontInputComponent::BindToInput()
{
	OwnerPawn = Cast<APawn>(GetOwner());

	if (OwnerPawn)
	{
		auto Controller = OwnerPawn->GetController();

		if (Controller)
		{
			InputComponent = OwnerPawn->GetController()->FindComponentByClass<UInputComponent>();
		}

		if (InputComponent)
		{
			InputComponent->BindAction("Interact", IE_Pressed, this, &UActiontInputComponent::OnActionPressed);
		}
	}
}

void UActiontInputComponent::OnActionPressed()
{
	OnInteractPressedEvent.Broadcast();
}
