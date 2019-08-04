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
	FORCEINLINE class UBoxComponent* GetSpawnBox() const { return SpawnBox; }

	// Returns center of box
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetVolumeCenter();
	
	// Health of enemy in current wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float CurrentWaveHealth;
	
	// Current round number
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WinLose")
	int RoundNumber;

protected:
	// Specifies the enemy to spawn
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AEnemySoldier> SpawnEnemySoldier;
	
	// Dummy timer handle for spawning
	FTimerHandle SpawnTimer;
	
	// Time interval between each enemy spawn within around and between 2 rounds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayTime;

private:
	// Specifies where enemies spawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* SpawnBox;
	
	void SpawnEnemy();
	
	// Number of enemies that need to be spawned in total for the round
	int EnemyToSpawn;
	
	// Number of enemies that have been spawned for the round
	int EnemySpawned;
	
	// Array of enemies on map right now
	UPROPERTY()
	TArray<AActor*> ExistingEnemies;

};
