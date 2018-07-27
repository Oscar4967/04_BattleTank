// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//GetSightRayHitLocation();

}

//end of tick



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *ControlledTank->GetName());
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector OurHitLocation; //Out parameter
	if (GetSightRayHitLocation(OurHitLocation)) //Has side effect, will ray-trace
	{
		UE_LOG(LogTemp, Warning, TEXT("OurHitLocation: %s"), *OurHitLocation.ToString());
		
			//TODO Tell controlled tank to aim at this point
	}
	
	
}

//Get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OurHitLocation) const
{
	OurHitLocation = FVector(1.0);
	return false;
}