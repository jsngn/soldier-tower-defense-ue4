// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretBullet.h"
#include "TimerManager.h"
#include "EnemySoldier.h"

// Sets default values
ATurretBullet::ATurretBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	OnActorBeginOverlap.AddDynamic(this, &ATurretBullet::OnOverlap);

}

// Called when the game starts or when spawned
void ATurretBullet::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(DummyTimerHandle, this, &ATurretBullet::Explode, 2.0f);
	
}

// Called every frame
void ATurretBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Moves missile every tick
	FVector Loc = GetActorLocation();
	Loc += (DeltaTime * Speed) * GetTransform().GetUnitAxis(EAxis::X); // DeltaTime * Speed gives the distance it moves, multiplied by unit vector in the x axis to add to Loc in terms of that axis
	SetActorLocation(Loc);

}

// Default implementation of the explode function, if not otherwise implemented in blueprints
void ATurretBullet::Explode_Implementation() {
	Destroy();  // Simply gets destroyed, no graphics
}

void ATurretBullet::OnOverlap(AActor* OverlappedActor, AActor* OtherActor) {
	AEnemySoldier* Enemy = Cast<AEnemySoldier>(OtherActor);

	if (Enemy) {
		Enemy->Attacked(Damage);
		GetWorldTimerManager().ClearTimer(DummyTimerHandle);
		Explode();
	}
}
