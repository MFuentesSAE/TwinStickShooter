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
	HideActor(actor, true);
	return actor;

}

AActor* UActorPool::FindFirstAvailableActor()
{
	for (AActor* actor : actorPool)
	{
		if (actor != nullptr && actor->IsHidden())
		{
			UE_LOG(LogTemp, Display, TEXT("Actor Found"));	
			return actor;
		}
	}

	UE_LOG(LogTemp, Display, TEXT("Actor Not Found, Creating New One"));	
	return InstancePoolActor(actorTemplate);
}

void UActorPool::HideActor(AActor* actorToHide, bool isHidden)
{
	actorToHide->SetActorHiddenInGame(isHidden);
	actorToHide->SetActorTickEnabled(!isHidden);
	actorToHide->SetActorEnableCollision(!isHidden);

}


// Called every frame
void UActorPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor* UActorPool::GetActorFromPool()
{
	AActor* actorFound = FindFirstAvailableActor();

	if (actorFound != nullptr)
	{
		HideActor(actorFound, false);
		return actorFound;
	}

	return nullptr;
}

