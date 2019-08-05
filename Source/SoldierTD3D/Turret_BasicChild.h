// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turret.h"
#include "Turret_BasicChild.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API ATurret_BasicChild : public ATurret
{
	GENERATED_BODY()
	
protected:
	// Override so we can spend money appropriately for this turret
	virtual void BeginPlay() override;

};
