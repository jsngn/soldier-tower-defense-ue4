// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SoldierTD3DGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "Tower.h"
#include "Engine/World.h"

ASoldierTD3DGameMode::ASoldierTD3DGameMode()
{
}

bool ASoldierTD3DGameMode::IsWin() {
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), ExistingTower);

	if (ExistingTower.Num() > 0) {  // Make sure there's still a tower because if tower destroyed then player doesn't win
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), ExistingSpawnVolume);

		if (ExistingSpawnVolume.Num() > 0) {
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(ExistingSpawnVolume[0]);
			
			if (SpawnVolume) {
				
				if (SpawnVolume->RoundNumber == WinRoundNumber) {
					return true;  // If the current round number equals the winning round number then player has won
				}
			}
		}
	}
	return false;

}

bool ASoldierTD3DGameMode::IsLose() {
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATower::StaticClass(), ExistingTower);
	
	// Player has lost if tower destroyed, otherwise player hasn't lost
	if (ExistingTower.Num() == 0) {
		return true;
	}
	return false;

}
