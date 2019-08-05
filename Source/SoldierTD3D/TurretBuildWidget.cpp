// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretBuildWidget.h"
#include "PlayerPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

bool UTurretBuildWidget::IsBuildable() {
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerPawn::StaticClass(), ExistingPlayerPawn);

	if (ExistingPlayerPawn.Num() > 0) {
		APlayerPawn* PlayerPawn = Cast<APlayerPawn>(ExistingPlayerPawn[0]);
		if (PlayerPawn) {
			return PlayerPawn->IsBuildAffordable();  // Calls player pawn's function to see if it has enough money for build
		}
	}

	return false;  // Fall back case (if no player pawn exists then you shouldn't be able to build anything)
}
