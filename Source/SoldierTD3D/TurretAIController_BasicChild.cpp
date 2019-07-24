// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretAIController_BasicChild.h"
#include "Perception/AISenseConfig_Sight.h"

// Lower perception range
ATurretAIController_BasicChild::ATurretAIController_BasicChild() {
	PrimaryActorTick.bCanEverTick = true;

	// Can change these to change turret's perception ability
	AISightRadius = 400.0f;
	AILoseSightRadius = AISightRadius + 1.0f;
	AISightAge = 7.0f;
	AIFieldOfView = 50.0f;

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);
}
