// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ToggleActorActiveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TWINSTICKSHOOTER_API UToggleActorActiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UToggleActorActiveComponent();

	UFUNCTION(BlueprintCallable)
	void SetActorActive(bool active);

	UFUNCTION(BlueprintCallable)
	void Naco();
	

protected:
	virtual void BeginPlay() override;
	
private:
	AActor* actor;
};
