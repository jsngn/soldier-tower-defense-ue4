// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnemySoldier.h"
#include "Perception/AISenseConfig_Sight.h"

ATurretAIController::ATurretAIController() {
	
	PrimaryActorTick.bCanEverTick = true;

	// Can change these to change turret's perception ability
	AISightRadius = 400.0f;
	AILoseSightRadius = AISightRadius + 1.0f;
	AISightAge = 7.0f;
	AIFieldOfView = 47.0f;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent")));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

}

void ATurretAIController::BeginPlay() {
	Super::BeginPlay();
	
	// Debugging only
	/*if (GetPerceptionComponent()) {
		UE_LOG(LogTemp, Warning, TEXT("AI System Set"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Error"));
	}*/

}

void ATurretAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	// Don't move these
	TArray<float> DistanceArray;
	TArray<AActor*> OutActors;
	TArray<AActor*>& OutActorsRef = OutActors;

	// Gets all enemies in FOV of turret and puts them in OutActors array
	GetPerceptionComponent()->GetCurrentlyPerceivedActors(*SightConfig->GetSenseImplementation(), OutActorsRef);

	// If any enemy present
	if (OutActors.Num() > 0) {
		// Build an array of distances between turret and each enemy in FOV
		for (size_t i = 0; i < OutActors.Num(); i++) {
			DistanceArray.Emplace(GetPawn()->GetDistanceTo(OutActors[i]));
		}

		// Sort so the smallest is at 0th position
		DistanceArray.Sort();

		// Aim turret at the closest enemy
		for (size_t i = 0; i < OutActors.Num(); i++) {
			if ((GetPawn()->GetDistanceTo(OutActors[i])) == DistanceArray[0]) {
				FVector EnemyLoc = OutActors[i]->GetActorLocation();
				this->SetFocalPoint(EnemyLoc);
			}
		}
	
		// Remove all elements for next tick
		OutActors.Empty();
	}
}
