// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret_BasicChild.h"

#include "PlayerPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"

void ATurret_BasicChild::BeginPlay() {

	AActor::BeginPlay(); // So the basic turret's money check doesn't happen; this turret is more expensive

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerPawn::StaticClass(), ExistingPlayerPawn);

	if (ExistingPlayerPawn.Num() > 0) {
		APlayerPawn* PlayerPawn = Cast<APlayerPawn>(ExistingPlayerPawn[0]);

		if (PlayerPawn) {
			UE_LOG(LogTemp, Warning, TEXT("About to spend upgrade money"));
			PlayerPawn->SpendTurretMoney();
		}
	}
}