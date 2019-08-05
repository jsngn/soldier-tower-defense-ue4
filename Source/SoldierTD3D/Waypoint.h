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

	// Order of this waypoint in sequence of waypoints in defined path
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waypoint", meta = (AllowPrivateAccess = "true"))
	int WaypointOrder;

public:
	
	// Returns this waypoint's order in path
	int GetWaypointOrder();
};
