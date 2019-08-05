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

	UFUNCTION(BlueprintCallable, Category = "WinLose")
	bool IsWin();

	UFUNCTION(BlueprintCallable, Category = "WinLose")
	bool IsLose();

private:
	UPROPERTY()
	TArray<AActor*> ExistingSpawnVolume;

	UPROPERTY()
	TArray<AActor*> ExistingTower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WinLose", meta = (AllowPrivateAccess = "true"))
	int WinRoundNumber;

};



