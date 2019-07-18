// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

};
