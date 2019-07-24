// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TurretBuildWidget.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API UTurretBuildWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	bool IsBuildable();

protected:

	UPROPERTY()
	TArray<AActor*> ExistingPlayerPawn;

};
