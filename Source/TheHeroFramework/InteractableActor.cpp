// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"
#include "AttributeComponent.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT ("MeshComp"));
	RootComponent = MeshComp;

	// Mesh block visibility for raycast
	MeshComp->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableActor::Interact_Implementation(AActor* ActorToInteractWith)
{
	if (!ActorToInteractWith)
		return;

	UE_LOG(LogTemp, Warning, TEXT ("Interacted with %s"), *GetName());

	// Find attribute component
	UAttributeComponent* AttributeComp = ActorToInteractWith->FindComponentByClass<UAttributeComponent>();

	// Character has attribute component and this BP has effect data means its for power up or power down
	if (AttributeComp && EffectData)
	{
		switch (EffectData->EffectType)
		{
			// Here I'm using switch case to only show that we can use power up to call different functions
			// for instance, speed up, jump boost or health boost
		case EEffectType::Health:
		case EEffectType::Energy:
		case EEffectType::Poison:
			AttributeComp->ApplyHealthChange(EffectData->HealthDelta, ActorToInteractWith);
			break;
		}

		

		UE_LOG(LogTemp, Warning, TEXT ("Effect Name %s, and lose or gain is %f"), *EffectData->EffectName, EffectData->HealthDelta);
	}

	// Call this trigger, which can perform animations in BP
	OnInteractTriggered(ActorToInteractWith);
}

