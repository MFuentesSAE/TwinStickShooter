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
	// Sets default values for this component's properties
	UActorPool();

	UPROPERTY(EditAnywhere)
	int deafultPoolSize = 10;

	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> actorPool;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorTemplate;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void ToggleActive(AActor* actor, bool active);
	AActor* FistAvailableActor();

public:	
	AActor* InstacePoolActor(TSubclassOf<AActor> actorReference);
	//AActor* InstacePoolActor(TSubclassOf<AActor> actorReference, FVector spawnLocation);

	AActor* GetActorFromPool();
	void ReturnActorToPool(AActor* actorToReturn);	
};
