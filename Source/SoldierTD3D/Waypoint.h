// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Waypoint.generated.h"

/**
 * 
 */
UCLASS()
class SOLDIERTD3D_API AWaypoint : public AStaticMeshActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoint", meta = (AllowPrivateAccess = "true"))
	int WaypointOrder;

public:
	int GetWaypointOrder();
};
