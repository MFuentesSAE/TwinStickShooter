// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPool.h"

// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UActorPool::BeginPlay()
{
	Super::BeginPlay();

	if (ActorTemplate == nullptr || deafultPoolSize <= 0)
	{
		return;
	}
	
	for (int i = 0; i < deafultPoolSize; i++)
	{
		InstacePoolActor(ActorTemplate);
	}
}

void UActorPool::ToggleActive(AActor* actor, bool active)
{
	actor->SetActorTickEnabled(false);
	actor->SetHidden(true);
	actor->SetActorEnableCollision(false);
}

AActor* UActorPool::FistAvailableActor()
{
	for (AActor* actor : actorPool)
	{
		if (!actor->IsHidden())
		{
			return actor;
		}
	}

	//Instance a new actor if an active one is not found
	return InstacePoolActor(ActorTemplate);
}

AActor* UActorPool::GetActorFromPool()
{
	return FistAvailableActor();
}

void UActorPool::ReturnActorToPool(AActor* actorToReturn)
{
	if (actorToReturn == nullptr)
	{
		return;
	}
	
	ToggleActive(actorToReturn, false);
}


AActor* UActorPool::InstacePoolActor(TSubclassOf<AActor> actorReference)
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	AActor* actor = GetWorld()->SpawnActor<AActor>(actorReference, SpawnInfo);

	if (actor == nullptr)
	{
		return nullptr;
	}
	
	actorPool.Add(actor);
	ToggleActive(actor, false);
	return actor;
}

