// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretAIController_UpgradedChild.h"
#include "Perception/AISenseConfig_Sight.h"

// Increase perception range
ATurretAIController_UpgradedChild::ATurretAIController_UpgradedChild() {
	PrimaryActorTick.bCanEverTick = true;

	// Can change these to change turret's perception ability
	AISightRadius = 500.0f;
	AILoseSightRadius = AISightRadius + 1.0f;
	AISightAge = 7.0f;
	AIFieldOfView = 360.0f;

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);
}
