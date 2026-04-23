// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IPooled.generated.h"

/**
 * 
 */
UINTERFACE(Blueprintable)
class TWINSTICKSHOOTER_API UIPooled : public UInterface
{
	GENERATED_BODY()
	
};

class IIPooled
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnSpawn(AActor* instigator);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void LifeTime(float time);

	virtual void OnSpawn_Implementation(AActor* instigator);
	virtual void LifeTime_Implementation(float time);
};





