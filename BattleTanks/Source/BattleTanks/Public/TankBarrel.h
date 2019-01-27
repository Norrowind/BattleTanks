// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downwoardspeed and +1 is max up movement
	void Elevate(float RalativeSpeed);

private:
	//Sencible default
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinDegreesElevation = 0.;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesElevation = 40.;

};
