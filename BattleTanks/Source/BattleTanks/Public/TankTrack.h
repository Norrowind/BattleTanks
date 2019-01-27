// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and apply force to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//Set throttle beetween -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	//Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDriveForce = 400000; //Assume tank mass of 40 tonne and acceleration in 1g

};
