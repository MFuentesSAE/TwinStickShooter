// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorUtilities.generated.h"

/**
 * 
 */
UCLASS()
class TWINSTICKSHOOTER_API UActorUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static void ToggleActorHidden(AActor* actor, bool hidden);
	
};
