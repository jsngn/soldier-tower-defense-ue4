// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurretBullet.generated.h"

UCLASS()
class SOLDIERTD3D_API ATurretBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurretBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurretBullet")
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TurretBullet")
	float Damage;

	// Box for detecting hit with enemy
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* DummyCollisionBox;

	// Function called when bullet hits enemy
	UFUNCTION()
	void OnBoxHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	// Explodes bullet, add visual effects if necessary
	UFUNCTION(BlueprintNativeEvent, Category = "TurretBullet")
	void Explode();

	FTimerHandle DummyTimerHandle;

};
