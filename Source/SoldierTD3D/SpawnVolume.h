// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySoldier.h"
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

protected:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AEnemySoldier> WhatToSpawn;

private:
	// Specifies where enemies spawn
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;

	void SpawnEnemy();
};