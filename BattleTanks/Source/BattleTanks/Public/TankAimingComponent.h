// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming states
UENUM()
enum class EFiringState:uint8
{
	Reloading,
	Aiming,
	Locked
};

//Forward declaration
class UTankBarrel;
class UTankTurret;

//Holds barrels properties and Elevate method
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	void AimAt(FVector OutHitLocation, float LaunchSpeed);
	
protected:
	//Fireing state
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;

private:

	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

};
