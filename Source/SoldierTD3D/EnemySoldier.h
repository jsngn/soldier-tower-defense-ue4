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

	// Moves character to all waypoints sequentially to make enemy move in defined path
	void MoveToWaypoints();
	
	// Amount of damage dealt by 1 enemy to tower
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
	UFUNCTION(BlueprintNativeEvent, Category = "Attack")
	float Attack();

	// C++ implementation just destroys enemy, but do special effects if necessary
	UFUNCTION(BlueprintNativeEvent, Category = "Health")
	void Death();
	
	// Updates enemy's max health for the current round
	UFUNCTION()
	void UpdateFullHealth(float CurrentWaveHealth);

private:
	// Waypoint which the character is currently at; must be set to 1 initially
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	int CurrentWaypoint;

	// Array of waypoints
	UPROPERTY()
	TArray<AActor*> Waypoints;
	
	// Array of player pawn (should contain 1 element only, but is array for purpose of game logic)
	UPROPERTY()
	TArray<AActor*> ExistingPlayerPawn;

};
