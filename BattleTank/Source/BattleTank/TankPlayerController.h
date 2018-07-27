// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
*
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void AimTowardsCrosshair(); //start the tank moving the barrel towards the crosshair location

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector&) const;

public:
	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


};