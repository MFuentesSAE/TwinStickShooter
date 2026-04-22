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

	UPROPERTY(EditAnywhere);
	int defaultSize = 10; //tamaño inicial del pool

	UPROPERTY(EditAnywhere);
	TArray<AActor*> actorPool; //lista

	UPROPERTY(EditAnywhere);
	TSubclassOf<AActor> actorTemplate; //el actor a instancear

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	AActor* InstancePoolActor(TSubclassOf<AActor> actorReference); //función para instancear actores
	AActor* FindFirstAvailableActor(); //Regresa el primer actor desactivado que encuentre.
	void HideActor(AActor* actorToHide, bool isHidden);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	AActor* GetActorFromPool(); //Obtener un actor 

		
};
