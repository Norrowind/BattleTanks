// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	//Start the tank moving the barrel, so that a shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

	//return OUT parametr, true if hit the landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const ;

	
};
