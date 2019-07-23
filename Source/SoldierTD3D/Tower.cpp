// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "EnemySoldier.h"
#include "Components/BoxComponent.h"
#include "Engine.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Make a dummy box to detect hits with enemy, make it the root
	DummyCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DummyCollisionBox"));
	DummyCollisionBox->SetSimulatePhysics(true);
	DummyCollisionBox->SetNotifyRigidBodyCollision(true);
	DummyCollisionBox->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	DummyCollisionBox->OnComponentHit.AddDynamic(this, &ATower::OnBoxHit);
	RootComponent = DummyCollisionBox;
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();

	// Calculates health stats at start of game
	CurrentHealth = FullHealth;
	CurrentHealthPercentage = float(CurrentHealth) / float(FullHealth);
	
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATower::OnBoxHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	if (OtherActor && (OtherActor != this) && (OtherComp)) {
		AEnemySoldier* Enemy = Cast<AEnemySoldier>(OtherActor);

		// Damage enemy and explodes if hit enemy
		if (Enemy) {
			DamageReceived = Enemy->Attack();
			
			if (DamageReceived > 0.f) {
				CurrentHealth -= DamageReceived; // Applies damage only if there's any damage
				CurrentHealthPercentage = float(CurrentHealth) / float(FullHealth); // No need to update this every tick because damage isn't guaranteed every tick

				// If no health left, kill the enemy  
				if (CurrentHealth <= 0.f)
				{
					Collapse();
				}
			}
		}
	}
}

void ATower::Collapse_Implementation() {
	Destroy();
	
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	}
}

bool ATower::SpendTurretMoney() {
	CurrentMoney -= TurretCost;
	if (CurrentMoney < 0) {
		CurrentMoney += TurretCost;
		UE_LOG(LogTemp, Warning, TEXT("Not enough to build; current money: %f"), CurrentMoney);
		return false;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Enough to build; current money: %f"), CurrentMoney);
		return true;
	}
}

void ATower::GainMoney() {
	CurrentMoney += KillGain;
	UE_LOG(LogTemp, Warning, TEXT("Money after gained: %f"), CurrentMoney);
}

FText ATower::GetMoneyText() {
	FString MoneyString = FString::FromInt(CurrentMoney);
	FText MoneyText = FText::FromString(MoneyString);
	return MoneyText;
}
