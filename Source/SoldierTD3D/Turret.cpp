// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create a dummy muzzle component where bullets are spawned from
	DummyMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("DummyMuzzle"));
	DummyMuzzle->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurret::Shoot() {

	if (AActor* NewProjectile = GetWorld()->SpawnActor(Projectile)) { // Attempts to spawn projectile, checks if successfully spawned the projectile
		
		// Gets current location & rotation of turret's muzzle
		FVector Loc = DummyMuzzle->GetComponentLocation();
		FRotator Rot = DummyMuzzle->GetComponentRotation();

		// Sets the location & rotation as those of the new projectile
		NewProjectile->SetActorLocation(Loc);
		NewProjectile->SetActorRotation(Rot);
	}
}
