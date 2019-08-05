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

	// Max health of the tower
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float FullHealth;

	// Current health
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	float CurrentHealth;

	// Current health as a percentage (for the heathbar widget)
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	float CurrentHealthPercentage;

	// Box for detecting hit with enemy
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* DummyCollisionBox;

	// Function called when enemy hits tower
	UFUNCTION()
	void OnBoxHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

protected:
	
	// C++ function just calls Destroy(); can add more in blueprints
	UFUNCTION(BlueprintNativeEvent, Category = "Health")
	void Collapse();
	
	// Amount of damage received from enemy
	float DamageReceived;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
