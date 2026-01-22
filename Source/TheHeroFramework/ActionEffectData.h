// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ActionEffectData.generated.h"

UENUM (BlueprintType)
enum class EEffectType : uint8
{
	Health	UMETA(DisplayName = "Burger"),
	Energy	UMETA(DisplayName = "Drink"),
	Poison  UMETA(DisplayName = "Poison")
};

/**
 * 
 */
UCLASS()
class THEHEROFRAMEWORK_API UActionEffectData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	EEffectType EffectType;

	// how much health to add or remove
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	float HealthDelta = 20.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Visuals")
	FString EffectName = "Health Boost";
};
