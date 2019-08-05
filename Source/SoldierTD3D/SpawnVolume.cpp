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
	
	// Make the box where enemies will be spawned from
	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
	// Initializes some values at start of game
	EnemyToSpawn = 1;
	EnemySpawned = 0;
	RoundNumber = 0;

}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemySoldier::StaticClass(), ExistingEnemies);

	if (ExistingEnemies.Num() == 0) {  // If all enemies have died or if at the start of game
		EnemyToSpawn = EnemyToSpawn * 2;  // Spawn 2x enemies of previous round or spawn 2 at start of game
		EnemySpawned = 0;  // Resets number of enemy that have spawned for the round to 0
		RoundNumber++;  // Increments round number

		CurrentWaveHealth = CurrentWaveHealth * 1.05; // 5% more health each round
		SpawnEnemy();
	}
}

FVector ASpawnVolume::GetVolumeCenter() {
	return SpawnBox->Bounds.Origin;
}


void ASpawnVolume::SpawnEnemy() {
	if (SpawnEnemySoldier) {
		UWorld* const World = GetWorld();

		if (World) {
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			FVector SpawnLoc = GetVolumeCenter();  // Spawn at center of box
			FRotator SpawnRot = FRotator::ZeroRotator;  // For this map, this makes them face forward in path
			
			World->SpawnActor<AEnemySoldier>(SpawnEnemySoldier, SpawnLoc, SpawnRot, SpawnParams)->UpdateFullHealth(CurrentWaveHealth);  // Spawn the enemy and give it the health that it should have for the current round
			EnemySpawned++;  // Increments number of enemies that have been spawned for the round
			
			// Keep spawning enemies with time delay between each spawn until enough enemies have been spawned for the current round
			if (EnemySpawned < (EnemyToSpawn)) {
				GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnEnemy, SpawnDelayTime, false);
			}
		}
	}
}
