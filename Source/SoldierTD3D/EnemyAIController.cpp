// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "EnemySoldier.h"
#include "Engine/World.h"

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) {
	AEnemySoldier* EnemySoldier = Cast<AEnemySoldier>(GetPawn());

	// Calls function to move character to all (remaining) waypoints in array when a move action is done
	if (EnemySoldier) {
		EnemySoldier->MoveToWaypoints();
	}
}