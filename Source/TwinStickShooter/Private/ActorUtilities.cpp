// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorUtilities.h"

void UActorUtilities::ToggleActorHidden(AActor* actor, bool hidden)
{
	if (actor == nullptr)
	{
		return;
	}

	actor->SetActorHiddenInGame(hidden);
	actor->SetActorTickEnabled(!hidden);
	actor->SetActorEnableCollision(!hidden);
}
