// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turret.h"
#include "Turret_UpgradedChild.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API ATurret_UpgradedChild : public ATurret
{
	GENERATED_BODY()
	
public:

	ATurret_UpgradedChild();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Downgrade")
	USceneComponent* DummySpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Downgrade")
	TSubclassOf<class ATurret> BasicTurret;
};
