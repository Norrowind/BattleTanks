// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankMovementComponent.h"
#include "TankAimingComponent.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	//Move Towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);
	
	//Aim at the player
	ControlledTank->FindComponentByClass<UTankAimingComponent>()->AimAt(PlayerTank->GetActorLocation());

	//TODO make fire work
	//ControlledTank->Fire();
}

