// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward declaration
class UTankAimingComponent; // TODO Is this really needed?

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPossessedTankDeath();

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	// How close the AI tank can get in centimeters
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 3000;

	virtual void SetPawn(APawn* InPawn) override;
};
