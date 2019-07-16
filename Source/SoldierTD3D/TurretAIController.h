// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TurretAIController.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API ATurretAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATurretAIController();

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;
	
	virtual void Tick(float DeltaTime) override;
	
	virtual FRotator GetControlRotation() const override;
	
	UFUNCTION()
	void OnPawnDetected(const TArray<AActor*>& DetectedEnemies);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret AI")
	float AISightRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret AI")
	float AILoseSightRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret AI")
	float AISightAge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret AI")
	// 180.0f makes it look all way round
	float AIFieldOfView;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Turret AI")
	class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Turret AI")
	bool bIsEnemyDetected;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Turret AI")
	float DistanceToPlayer;
};
