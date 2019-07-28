// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretBullet.h"
#include "TimerManager.h"
#include "EnemySoldier.h"
#include "Components/BoxComponent.h"

// Sets default values
ATurretBullet::ATurretBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Make a dummy box to detect hits with enemy, make it the root
	DummyCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DummyCollisionBox"));
	DummyCollisionBox->SetSimulatePhysics(true);
	DummyCollisionBox->SetNotifyRigidBodyCollision(true);
	DummyCollisionBox->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	DummyCollisionBox->OnComponentHit.AddDynamic(this, &ATurretBullet::OnBoxHit);
	RootComponent = DummyCollisionBox;

}

// Called when the game starts or when spawned
void ATurretBullet::BeginPlay()
{
	Super::BeginPlay();

	// If bullet doesn't hit any enemy in 2 seconds, just destroy
	GetWorldTimerManager().SetTimer(ExplodeTimerHandle, this, &ATurretBullet::Explode, ExplodeDelayTime);
	
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

// Simply destroys bullet, no graphics
void ATurretBullet::Explode_Implementation() {
	Destroy();
}

void ATurretBullet::OnBoxHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	if (OtherActor && (OtherActor != this) && (OtherComp)) {
		AEnemySoldier* Enemy = Cast<AEnemySoldier>(OtherActor);

		// Damage enemy and explodes if hit enemy
		if (Enemy) {
			Enemy->Attacked(Damage);
			GetWorldTimerManager().ClearTimer(ExplodeTimerHandle);
			Explode();
		}
	}
}
