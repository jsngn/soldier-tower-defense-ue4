// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/BoxComponent.h"

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
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetVolumeCenter() {
	return WhereToSpawn->Bounds.Origin;
}

void ASpawnVolume::SpawnEnemy() {
	if (WhatToSpawn) {
		UWorld* const World = GetWorld();
		
		if (World) {
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			FVector SpawnLoc = GetVolumeCenter();
			FRotator SpawnRot;
			SpawnRot.Yaw = 0.0f;
			SpawnRot.Pitch = 0.0f;
			SpawnRot.Roll = 0.0f;

			World->SpawnActor<AEnemySoldier>(WhatToSpawn, SpawnLoc, SpawnRot, SpawnParams);
		}
	}
}
