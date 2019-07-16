// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "EnemySoldier.h"
#include "Perception/AISenseConfig_Sight.h"

ATurretAIController::ATurretAIController() {
	
	PrimaryActorTick.bCanEverTick = true;

	AISightRadius = 500.0f;
	AILoseSightRadius = AISightRadius + 1.0f;
	AISightAge = 5.0f;
	AIFieldOfView = 180.0f;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ATurretAIController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

	bIsEnemyDetected = false;
}

void ATurretAIController::BeginPlay() {
	Super::BeginPlay();
	
	if (GetPerceptionComponent()) {
		UE_LOG(LogTemp, Warning, TEXT("AI System Set"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Error"));
	}

}

void ATurretAIController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	if (bIsEnemyDetected) {
		AEnemySoldier* Enemy = Cast<AEnemySoldier>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	}
}

void ATurretAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

FRotator ATurretAIController::GetControlRotation() const {
	if (!GetPawn()) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

// Called every time enemy enters field of view or exits field of view
void ATurretAIController::OnPawnDetected(const TArray<AActor*>& DetectedEnemies) { // Array contains ONLY the actor that triggered the event
	TArray<float> DistanceArray;

	for (size_t i = 0; i < DetectedEnemies.Num(); i++) {
		DistanceArray.Emplace(GetPawn()->GetDistanceTo(DetectedEnemies[i]));
	}

	for (size_t i = 0; i < DistanceArray.Num(); i++) {
		UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), DistanceArray[i]);
	}

	DistanceArray.Sort();
	UE_LOG(LogTemp, Warning, TEXT("Smallest distance in current array: %f"), DistanceArray[0]);

	DistanceArray.Empty();

	UE_LOG(LogTemp, Warning, TEXT("------------------"));

	bIsEnemyDetected = true;
}