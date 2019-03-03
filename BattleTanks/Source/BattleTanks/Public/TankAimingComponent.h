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
	Locked,
	OutOfAmmo
};

//Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;



//Holds barrels properties and Elevate method
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	EFiringState GetFiringState() const;

	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;
	
protected:

	//Fireing state
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:

	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoved();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	FVector AimDirection;

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf< AProjectile > ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 8000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeinSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	int32 RoundsLeft = 3;

	double LastFireTime = 0;



};
