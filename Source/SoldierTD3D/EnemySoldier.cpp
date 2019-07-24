// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySoldier.h"
#include "EnemyAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Waypoint.h"
#include "PlayerPawn.h"

// Sets default values
AEnemySoldier::AEnemySoldier()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AEnemySoldier::BeginPlay()
{
	Super::BeginPlay();
	
	// Fills array of waypoints; this array is not ordered
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), Waypoints);
	
	// Dsetermines movement
	CurrentWaypoint = 1;
	MoveToWaypoints();

}

// Called every frame
void AEnemySoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Current wave health: %f"), FullHealth);

}

// Called to bind functionality to input
void AEnemySoldier::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemySoldier::MoveToWaypoints() {
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());

	if (EnemyAIController) { // Only proceed if cast is successful
		
		if (CurrentWaypoint <= Waypoints.Num()) { // Only proceed if current waypoint is still less than length of waypoints array (total available waypoints)
			
			for (AActor* Waypoint : Waypoints) { // Iterate through the entire waypoints array
				AWaypoint* WaypointIndex = Cast<AWaypoint>(Waypoint);
				
				if (WaypointIndex) { // Only proceed if waypoint casting is successful

					if (WaypointIndex->GetWaypointOrder() == CurrentWaypoint) { // If the order of the waypoint we're looking at equals the current waypoint number
						
						EnemyAIController->MoveToActor(WaypointIndex, 1.f); // then move to that waypoint
						
						CurrentWaypoint++; // Adds 1 to current waypoint for next time
						
						break; // No need to loop anymore if enemy moved
					}
				}
			}
		}
	}
}

void AEnemySoldier::Attacked(float DamageAmount) {

	if (DamageAmount > 0.f) {
		CurrentHealth -= DamageAmount; // Applies damage only if there's any damage
		CurrentHealthPercentage = float(CurrentHealth) / float(FullHealth); // No need to update this every tick because damage isn't guaranteed every tick
		
		// If no health left, kill the enemy  
		if (CurrentHealth <= 0.f)
		{

			UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerPawn::StaticClass(), ExistingPlayerPawn);

			// More money for tower if enemy killed
			if (ExistingPlayerPawn.Num() > 0) {
				APlayerPawn* PlayerPawn = Cast<APlayerPawn>(ExistingPlayerPawn[0]);
				if (PlayerPawn) {
					PlayerPawn->GainMoney();
				}
			}

			Death();
		}
	}
}

float AEnemySoldier::Attack() {
	Death(); // Disappears off screen too
	return Damage; // Returns damage amount, tower will handle getting hurt
}

void AEnemySoldier::Death_Implementation() {
	Destroy();

}

void AEnemySoldier::UpdateFullHealth(float CurrentWaveHealth) {
	FullHealth = CurrentWaveHealth;
	CurrentHealth = FullHealth;
	CurrentHealthPercentage = float(CurrentHealth) / float(FullHealth);
}
