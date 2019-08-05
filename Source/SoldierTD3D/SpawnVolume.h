// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class SOLDIERTD3D_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Returns the box component specifying where to spawn
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	// Returns center of box
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetVolumeCenter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float CurrentWaveHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WinLose")
	int RoundNumber;

protected:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AEnemySoldier> WhatToSpawn;

	FTimerHandle SpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayTime;

private:
	// Specifies where enemies spawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	void SpawnEnemy();

	int EnemyToSpawn;

	int EnemySpawned;

	UPROPERTY()
	TArray<AActor*> ExistingEnemies;

};
