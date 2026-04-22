// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPool.h"

// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorPool::BeginPlay()
{
	Super::BeginPlay();

	if (actorTemplate == nullptr || defaultSize <= 0) 
	{
		return;
	}

	for (int i = 0; i < defaultSize; i++) 
	{
		InstancePoolActor(actorTemplate);
	}
	
}

AActor* UActorPool::InstancePoolActor(TSubclassOf<AActor> actorReference)
{
	FActorSpawnParameters spawnInfo;
	spawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; //setear que siempre aparezca el objeto

	AActor* actor = GetWorld()->SpawnActor<AActor>(actorReference, spawnInfo); // crear al actor

	if (actor == nullptr) //verificar si es nulo
	{
		return nullptr;
	}

	actorPool.Add(actor);
	HideActor(actor);
	return actor;

}

AActor* UActorPool::FindFirstAvailableActor()
{
	return nullptr;
}

void UActorPool::HideActor(AActor* actorToHide)
{
	actorToHide->SetActorHiddenInGame(true);
	actorToHide->SetActorTickEnabled(false);
	actorToHide->SetActorEnableCollision(false);

}


// Called every frame
void UActorPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor* UActorPool::GetActorFromPool()
{
	return nullptr;
}

