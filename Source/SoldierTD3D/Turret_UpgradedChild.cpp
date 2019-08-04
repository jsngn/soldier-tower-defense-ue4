// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret_UpgradedChild.h"
#include "PlayerPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

void ATurret_UpgradedChild::BeginPlay() {

	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerPawn::StaticClass(), ExistingPlayerPawn);

	if (ExistingPlayerPawn.Num() > 0) {
		APlayerPawn* PlayerPawn = Cast<APlayerPawn>(ExistingPlayerPawn[0]);

		if (PlayerPawn) {
			PlayerPawn->SpendUpgradeTurretMoney();
		}
	}
}
