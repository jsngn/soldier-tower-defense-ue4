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
	UFUNCTION()
		bool SpendTurretMoney();

	UFUNCTION()
		void GainMoney();

	UFUNCTION(BlueprintPure, Category = "Economy")
		FText GetMoneyText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy")
		int CurrentMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy")
		int TurretCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy")
		int KillGain;
};
