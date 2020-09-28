// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectReplicated.generated.h"


UCLASS(BlueprintType)
class SURVIVAL_API UObjectReplicated : public UObject
{
	GENERATED_BODY()

public:
	virtual bool IsSupportedForNetworking () const override { return true; };
	
};
