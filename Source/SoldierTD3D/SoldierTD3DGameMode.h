// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SoldierTD3DGameMode.generated.h"

UCLASS(minimalapi)
class ASoldierTD3DGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASoldierTD3DGameMode();
	
	// Checks if player has won
	UFUNCTION(BlueprintCallable, Category = "WinLose")
	bool IsWin();
	
	// Checks if player has lost
	UFUNCTION(BlueprintCallable, Category = "WinLose")
	bool IsLose();

private:
	// Array of spawn volume (should have only 1 element but is array for game logic's purpose)
	UPROPERTY()
	TArray<AActor*> ExistingSpawnVolume;
	
	// Array of tower (should have only 1 element but is array for game logic's purpose)
	UPROPERTY()
	TArray<AActor*> ExistingTower;
	
	// Number of rounds player needs to pass to win
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WinLose", meta = (AllowPrivateAccess = "true"))
	int WinRoundNumber;

};



