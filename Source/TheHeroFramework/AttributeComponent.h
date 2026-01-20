// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"

// Sends old health, new health, instigator
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHealthChanged, float, OldHealth, float, NewHealth, AActor*, Instigator);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEHEROFRAMEWORK_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributeComponent();

protected:
	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	float Health = 100.0f;

	UPROPERTY (EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	float MaxHealth = 100.0f;

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY (BlueprintAssignable, Category = "Events")
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void ApplyHealthChange(float Delta, AActor* Instigator);
};
