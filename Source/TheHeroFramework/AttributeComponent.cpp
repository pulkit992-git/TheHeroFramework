// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeComponent.h"

// Sets default values for this component's properties
UAttributeComponent::UAttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAttributeComponent::ApplyHealthChange(float Delta, AActor* Instigator)
{
	float OldHealth = Health;

	// Clams to make sure that health never goes below 0 or above max health
	Health = FMath::Clamp(Health + Delta, 0.0f, MaxHealth);

	if (OldHealth != Health)
	{
		// Broadcast the signal and any UI or sound listening will react.
		OnHealthChanged.Broadcast(OldHealth, Health, Instigator);
	}
}

