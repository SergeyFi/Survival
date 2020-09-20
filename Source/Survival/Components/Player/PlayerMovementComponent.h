// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVAL_API UPlayerMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	
private:

    	class UInputComponent* InputComponent;
    
    	class APawn* OwnerPawn;
    	
    	void BindToInputComponent();
    
    	void MoveForward(float Value);
    
    	void MoveRight(float Value);
    
    	void Turn(float Value);
    
    	void LookUp(float Value);
		
};
