// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Turret.generated.h"

class ATower;
UCLASS()
class SOLDIERTD3D_API ATurret : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATurret();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Shoot();

	// Dummy muzzle component to spawn the bullets from
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret")
	USceneComponent* DummyMuzzle;

private:

	// Select the blueprint/C++ class for the projectile that will be fired from turret
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> Projectile;

	UPROPERTY()
	TArray<AActor*> ExistingTower;

};
