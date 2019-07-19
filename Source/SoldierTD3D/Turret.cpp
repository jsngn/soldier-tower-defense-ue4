// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DummyMuzzle = CreateDefaultSubobject<USceneComponent>(TEXT("DummyMuzzle"));
	DummyMuzzle->AttachTo(RootComponent);


	/*TArray<UStaticMeshComponent*> StaticMeshes;
	this->GetComponents<UStaticMeshComponent>(StaticMeshes);
	if (StaticMeshes.Num() > 0) {
		
		UE_LOG(LogTemp, Warning, TEXT("Mesh attachment attempted"));
	}*/

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
	//bShoot = false;

}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (bShoot) {
	//	UE_LOG(LogTemp, Warning, TEXT("Permission to shoot"));
	//	
	//	if (AActor * NewProjectile = GetWorld()->SpawnActor(Projectile)) { // Attempts to spawn projectile, checks if successfully spawned the projectile
	//		UE_LOG(LogTemp, Warning, TEXT("Spawning projectile attempted"));
	//		// Gets current location & rotation of turret's muzzle
	//		FVector Loc = DummyMuzzle->GetComponentLocation(); // StaticMeshes[0]
	//		FRotator Rot = DummyMuzzle->GetComponentRotation();

	//		// Sets the location & rotation as those of the new projectile
	//		NewProjectile->SetActorLocation(Loc);
	//		NewProjectile->SetActorRotation(Rot);

	//		bShoot = false;
	//	}
	//}
	//else {
	//	UE_LOG(LogTemp, Warning, TEXT("No permission to shoot"));
	//}

}

// Called to bind functionality to input
void ATurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurret::Shoot() {
	UE_LOG(LogTemp, Warning, TEXT("Shoot accessed"));
	//bShoot = true;

	if (AActor* NewProjectile = GetWorld()->SpawnActor(Projectile)) { // Attempts to spawn projectile, checks if successfully spawned the projectile
		UE_LOG(LogTemp, Warning, TEXT("Spawning projectile attempted"));
		// Gets current location & rotation of turret's muzzle
		FVector Loc = DummyMuzzle->GetComponentLocation(); // StaticMeshes[0]
		FRotator Rot = DummyMuzzle->GetComponentRotation();

		// Sets the location & rotation as those of the new projectile
		NewProjectile->SetActorLocation(Loc);
		NewProjectile->SetActorRotation(Rot);
	}
}
