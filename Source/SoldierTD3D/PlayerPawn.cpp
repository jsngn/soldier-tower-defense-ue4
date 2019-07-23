// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

bool APlayerPawn::SpendTurretMoney() {
	CurrentMoney -= TurretCost;
	if (CurrentMoney < 0) {
		CurrentMoney += TurretCost;
		UE_LOG(LogTemp, Warning, TEXT("Not enough to build; current money: %f"), CurrentMoney);
		return false;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Enough to build; current money: %f"), CurrentMoney);
		return true;
	}
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