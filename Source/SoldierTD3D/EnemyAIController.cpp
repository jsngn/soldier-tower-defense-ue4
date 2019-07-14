// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "EnemySoldier.h"
#include "Engine/World.h"

void AEnemyAIController::BeginPlay() {
	Super::BeginPlay();

}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) {
	AEnemySoldier* EnemySoldier = Cast<AEnemySoldier>(GetPawn());

	if (EnemySoldier) {
		EnemySoldier->MoveToWaypoints();
	}
}