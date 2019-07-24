// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret_UpgradedChild.h"
#include "PlayerPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Turret.h"

ATurret_UpgradedChild::ATurret_UpgradedChild() {

	DummySpawn = CreateDefaultSubobject<USceneComponent>(TEXT("DummySpawn"));
	DummySpawn->AttachTo(RootComponent);

}

void ATurret_UpgradedChild::BeginPlay() {

	AActor::BeginPlay(); // So the basic turret's money check doesn't happen; this turret is more expensive

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerPawn::StaticClass(), ExistingPlayerPawn);

	if (ExistingPlayerPawn.Num() > 0) {
		APlayerPawn* PlayerPawn = Cast<APlayerPawn>(ExistingPlayerPawn[0]);

		if (PlayerPawn) {
			
			// Checks if we have enough money to upgrade turret; destroy upgrade immediately if not
			if (PlayerPawn->SpendUpgradeTurretMoney() == false) {

				FVector Loc = DummySpawn->GetComponentLocation();
				FRotator Rot = DummySpawn->GetComponentRotation();
				
				Destroy();
				
				if (BasicTurret) {
					UE_LOG(LogTemp, Warning, TEXT("Basic turret check passed"));
					FActorSpawnParameters SpawnParams;
					SpawnParams.Owner = this;
					SpawnParams.Instigator = Instigator;
					GetWorld()->SpawnActor<ATurret>(BasicTurret, Loc, Rot, SpawnParams);
				}
			}
		}
	}
}