// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "PlayerPawn.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API APlayerPawn : public ASpectatorPawn
{
	GENERATED_BODY()
	
public:
	
	// Checks if player has enough money to build 1 turret
	UFUNCTION()
	bool IsBuildAffordable();
	
	// Checks if player has enough money to upgrade 1 turret
	UFUNCTION()
	bool IsUpgradeAffordable();
	
	// Spends the money on building 1 turret
	UFUNCTION()
	void SpendTurretMoney();
	
	// Spends the money on upgrading 1 turret
	UFUNCTION()
	void SpendUpgradeTurretMoney();
	
	// Increases money from killing 1 enemy
	UFUNCTION()
	void GainMoney();
	
	// Gets the text of money amount for UI
	UFUNCTION(BlueprintPure, Category = "Economy")
	FText GetMoneyText();
	
private:

	// Stores current money amount
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy", meta = (AllowPrivateAccess = "true"))
	int CurrentMoney;
	
	// Stores the cost for building 1 turret
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy", meta = (AllowPrivateAccess = "true"))
	int TurretCost;
	
	// Stores the cost for upgrading 1 turret
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy", meta = (AllowPrivateAccess = "true"))
	int UpgradeTurretCost;
	
	// Amount of money gained from killing 1 enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy", meta = (AllowPrivateAccess = "true"))
	int KillGain;
};
