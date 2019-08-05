// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

void APlayerPawn::SpendTurretMoney() {
	CurrentMoney -= TurretCost;
	
}

void APlayerPawn::SpendUpgradeTurretMoney() {
	UE_LOG(LogTemp, Warning, TEXT("Current money is now: %i "), CurrentMoney);
	CurrentMoney -= UpgradeTurretCost;
	UE_LOG(LogTemp, Warning, TEXT("Current money is now: %i "), CurrentMoney);
}

void APlayerPawn::GainMoney() {
	CurrentMoney += KillGain;
	UE_LOG(LogTemp, Warning, TEXT("Money after gained: %f"), CurrentMoney);
}

FText APlayerPawn::GetMoneyText() {
	FString MoneyString = FString::FromInt(CurrentMoney);
	FText MoneyText = FText::FromString(MoneyString);
	return MoneyText;
}

bool APlayerPawn::IsBuildAffordable() {
	if (CurrentMoney >= TurretCost) {
		return true;
	}
	return false;
}

bool APlayerPawn::IsUpgradeAffordable() {
	if (CurrentMoney >= UpgradeTurretCost) {
		return true;
	}
	return false;
}
