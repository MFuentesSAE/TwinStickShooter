
#include "ToggleActorActiveComponent.h"

// Sets default values for this component's properties
UToggleActorActiveComponent::UToggleActorActiveComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	actor = GetOwner();
}

void UToggleActorActiveComponent::SetActorActive(bool active)
{
	if (actor == nullptr)
	{
		return;
	}
	
	actor->SetActorHiddenInGame(!active);
	actor->SetActorTickEnabled(active);
	actor->SetActorEnableCollision(active);
	
}

void UToggleActorActiveComponent::Naco()
{
}

void UToggleActorActiveComponent::BeginPlay()
{
	Super::BeginPlay();
}

