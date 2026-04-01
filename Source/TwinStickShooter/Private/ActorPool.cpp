
#include "ActorPool.h"

#include "ToggleActorActiveComponent.h"

UActorPool::UActorPool()
{
	PrimaryComponentTick.bCanEverTick = false;
}


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
	actor->SetActorHiddenInGame(!active);
	actor->SetActorTickEnabled(active);
	actor->SetActorEnableCollision(active);
}

AActor* UActorPool::FindFistAvailableActor()
{
	for (AActor* actor : actorPool)
	{
		if (actor != nullptr && actor->IsHidden())
		{
			return actor;
		}
	}

	//Instance a new actor if all actors are active
	return InstacePoolActor(ActorTemplate);
}

AActor* UActorPool::GetActorFromPool()
{
	AActor* actor = FindFistAvailableActor();
	ToggleActive(actor, true);
	return actor;
}

AActor* UActorPool::GetActorFromPoolSetPosition(FVector position)
{
	AActor* actor = GetActorFromPool();
	actor->SetActorLocation(position);
	return actor;
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
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* actor = GetWorld()->SpawnActor<AActor>(actorReference, SpawnInfo);

	if (actor == nullptr)
	{
		return nullptr;
	}
	
	actorPool.Add(actor);
	ToggleActive(actor, false);
	return actor;
}

