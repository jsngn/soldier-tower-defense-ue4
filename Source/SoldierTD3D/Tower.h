// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS()
class SOLDIERTD3D_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

	// Max health of the enemy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float FullHealth;

	// Current health
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	float CurrentHealth;

	// Current health as a percentage (for the heathbar widget)
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	float CurrentHealthPercentage;

	float DamageReceived;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy")
	int CurrentMoney;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy")
	int TurretCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Economy")
	int KillGain;

	// Box for detecting hit with enemy
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* DummyCollisionBox;

	// Function called when bullet hits enemy
	UFUNCTION()
	void OnBoxHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	bool SpendTurretMoney();

	UFUNCTION()
	void GainMoney();

	UFUNCTION(BlueprintPure, Category = "Economy")
	FText GetMoneyText();

protected:

	UFUNCTION(BlueprintNativeEvent, Category = "TurretBullet")
	void Collapse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
