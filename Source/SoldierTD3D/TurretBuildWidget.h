// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TurretBuildWidget.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API UTurretBuildWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	// Checks if player has enough money to build 1 turret
	UFUNCTION(BlueprintCallable)
	bool IsBuildable();

protected:
	
	// Array of existing player pawns (should have only 1 element, but is array for game logic's purpose)
	UPROPERTY()
	TArray<AActor*> ExistingPlayerPawn;

};
