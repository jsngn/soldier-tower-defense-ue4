// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretUpgradeWidget.h"
#include "PlayerPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

bool UTurretUpgradeWidget::IsUpgradable() {
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerPawn::StaticClass(), ExistingPlayerPawn);

	if (ExistingPlayerPawn.Num() > 0) {
		APlayerPawn* PlayerPawn = Cast<APlayerPawn>(ExistingPlayerPawn[0]);
		if (PlayerPawn) {
			return PlayerPawn->IsUpgradeAffordable();  // Call's player pawn's function to check affordability
		}
	}

	return false;  // Fallback case (shouldn't be able to upgrade anything if no player pawn)
}
