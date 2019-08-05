// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

void APlayerPawn::SpendTurretMoney() {
	CurrentMoney -= TurretCost;
	
}

void APlayerPawn::SpendUpgradeTurretMoney() {
	CurrentMoney -= UpgradeTurretCost;
		
}

void APlayerPawn::GainMoney() {
	CurrentMoney += KillGain;

}

FText APlayerPawn::GetMoneyText() {
	// Convert to string first, then text
	FString MoneyString = FString::FromInt(CurrentMoney);
	FText MoneyText = FText::FromString(MoneyString);
	return MoneyText;
	
}

bool APlayerPawn::IsBuildAffordable() {
	return CurrentMoney >= TurretCost;
	
}

bool APlayerPawn::IsUpgradeAffordable() {
	return CurrentMoney >= UpgradeTurretCost;
	
}
