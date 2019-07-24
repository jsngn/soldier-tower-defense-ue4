// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TurretUpgradeWidget.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API UTurretUpgradeWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	bool IsUpgradable();

protected:

	UPROPERTY()
	TArray<AActor*> ExistingPlayerPawn;

};
