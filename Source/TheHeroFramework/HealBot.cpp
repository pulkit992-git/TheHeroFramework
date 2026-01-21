// Fill out your copyright notice in the Description page of Project Settings.


#include "HealBot.h"
#include "GameplayInterface.h"

// Sets default values
AHealBot::AHealBot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHealBot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHealBot::TriggerInteract(AActor* ActorToInteractWith)
{
	// checks if the actor has the interface and call the function safely
	if (ActorToInteractWith->Implements<UGameplayInterface>())
	{
		IGameplayInterface::Execute_Interact(ActorToInteractWith, this);
	}
}

