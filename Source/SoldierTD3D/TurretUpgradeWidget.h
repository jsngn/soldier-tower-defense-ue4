// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TurretUpgradeWidget.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API UTurretUpgradeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	// Checks if player has enough money to upgrade 1 turret
	UFUNCTION(BlueprintCallable)
	bool IsUpgradable();

protected:
	
	// Array of existing player pawns (should have only 1 element, but is array for game logic's purpose)
	UPROPERTY()
	TArray<AActor*> ExistingPlayerPawn;

};
