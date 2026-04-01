// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TWINSTICKSHOOTER_API UActorPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	UActorPool();

	UPROPERTY(EditAnywhere)
	int deafultPoolSize = 10;

	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> actorPool;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorTemplate;

protected:
	virtual void BeginPlay() override;
	virtual void ToggleActive(AActor* actor, bool active);
	AActor* FindFistAvailableActor();

public:
	UFUNCTION(BlueprintCallable)
	AActor* InstacePoolActor(TSubclassOf<AActor> actorReference);

	UFUNCTION(BlueprintCallable)
	AActor* GetActorFromPool();

	UFUNCTION(BlueprintCallable)
	AActor* GetActorFromPoolSetPosition(FVector position);

	UFUNCTION(BlueprintCallable)
	void ReturnActorToPool(AActor* actorToReturn);	
};
