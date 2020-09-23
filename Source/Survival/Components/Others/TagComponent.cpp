// Fill out your copyright notice in the Description page of Project Settings.


#include "TagComponent.h"

// Sets default values for this component's properties
UTagComponent::UTagComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

FGameplayTagContainer UTagComponent::GetTags()
{
	return Tags;
}
