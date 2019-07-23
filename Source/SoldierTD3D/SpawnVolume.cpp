// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "EnemySoldier.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
	EnemyToSpawn = 1;
	EnemySpawned = 0;

}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySoldier::StaticClass(), ExistingEnemies);

	UE_LOG(LogTemp, Warning, TEXT("Enemy existing in tick %i "), ExistingEnemies.Num());

	if (ExistingEnemies.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("If statement in loop accessed"));
		EnemyToSpawn = EnemyToSpawn * 2;
		EnemySpawned = 0;

		SpawnEnemy();
	}
}

FVector ASpawnVolume::GetVolumeCenter() {
	return WhereToSpawn->Bounds.Origin;
}


void ASpawnVolume::SpawnEnemy() {
	UE_LOG(LogTemp, Warning, TEXT("Spawn function accessed"));
	if (WhatToSpawn) {
		UE_LOG(LogTemp, Warning, TEXT("What to spawn exists"));
		UWorld* const World = GetWorld();

		if (World) {
			UE_LOG(LogTemp, Warning, TEXT("World exists"));
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			FVector SpawnLoc = GetVolumeCenter();
			FRotator SpawnRot = FRotator::ZeroRotator;
			
			World->SpawnActor<AEnemySoldier>(WhatToSpawn, SpawnLoc, SpawnRot, SpawnParams);
			EnemySpawned++;

			UE_LOG(LogTemp, Warning, TEXT("Enemy to spawn %i "), EnemyToSpawn);
			UE_LOG(LogTemp, Warning, TEXT("Enemy spawned %i "), EnemySpawned);
			if (EnemySpawned < (EnemyToSpawn)) {
				GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnEnemy, SpawnDelayTime, false);
			}
		}
	}
}
