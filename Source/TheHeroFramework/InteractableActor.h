// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayInterface.h"
#include "ActionEffectData.h"
#include "InteractableActor.generated.h"

UCLASS()
class THEHEROFRAMEWORK_API AInteractableActor : public AActor, public IGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Interaction")
	UActionEffectData* EffectData;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// Implementatoin of interface
	virtual void Interact_Implementation(AActor* ActorToInteractWith) override;

	// Helper function to trigger in BP
	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void OnInteractTriggered(AActor* ActorToInteractWith);
};
