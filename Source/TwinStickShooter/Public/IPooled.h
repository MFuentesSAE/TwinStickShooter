// IPooled.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPooled.generated.h"

UINTERFACE(Blueprintable)
class UIPooled : public UInterface
{
	GENERATED_BODY()
};

class IIPooled
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pooled Object")
	void OnSpawn();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Pooled Object")
	void Lifetime(float Time, UActorPool* actorPool);
	
	virtual void OnSpawn_Implementation();
	virtual void Lifetime_Implementation(float Time, UActorPool* ActorPool);
};