// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Waypoint.h"
#include "EnemySoldier.h"

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
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), Waypoints);
	MoveToWaypoints();
}

// Called every frame
void AEnemySoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemySoldier::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemySoldier::MoveToWaypoints() {
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());

	if (EnemyAIController) {
		
		if (CurrentWaypoint <= Waypoints.Num()) {
			
			for (AActor* Waypoint : Waypoints) {
				AWaypoint* WaypointIndex = Cast<AWaypoint>(Waypoint);
				
				if (WaypointIndex) {

					if (WaypointIndex->GetWaypointOrder() == CurrentWaypoint) {
						
						EnemyAIController->MoveToActor(WaypointIndex, 1.f);
						
						CurrentWaypoint++;
						
						break;
					}
				}
			}
		}
	}
}
