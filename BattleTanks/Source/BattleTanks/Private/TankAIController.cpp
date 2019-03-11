// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankMovementComponent.h"
#include "TankAimingComponent.h"
#include "Tank.h" //So we can implement OnDeath

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	//Move Towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);
	
	//Aim at the player
	auto AimingComponent = ControlledTank-> FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire();
	}
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedTank = Cast<ATank>(InPawn);
		if (!ensure(PossesedTank)) { return; }
		PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossesedTankDeath);
	}

}

void ATankAIController::OnPossesedTankDeath()
{
	auto PossesedTank = GetPawn();
	if (!ensure(PossesedTank)) { return; }
	PossesedTank->DetachFromControllerPendingDestroy();
}

