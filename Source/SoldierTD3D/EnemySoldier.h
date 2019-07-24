// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "EnemySoldier.generated.h"

UCLASS()
class SOLDIERTD3D_API AEnemySoldier : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemySoldier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Moves character to all waypoints sequentially
	void MoveToWaypoints();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float Damage;

	// Max health of the enemy
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	float FullHealth;

	// Current health
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	float CurrentHealth;

	// Current health as a percentage (for the heathbar widget)
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	float CurrentHealthPercentage;

	// Handles receiving damage
	UFUNCTION()
	void Attacked(float DamageAmount);

	// Handles dealing damage to tower
	UFUNCTION()
	float Attack();

	// C++ implementation just destroys enemy, but do visual effects if necessary
	UFUNCTION(BlueprintNativeEvent, Category = "Health")
	void Death();

	UFUNCTION()
	void UpdateFullHealth(float CurrentWaveHealth);

private:
	// Waypoint which the character is currently at; must be set to 1 initially
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	int CurrentWaypoint;

	// Array of waypoints
	UPROPERTY()
	TArray<AActor*> Waypoints;

	UPROPERTY()
	TArray<AActor*> ExistingPlayerPawn;

};
