// Copyright Oscar Pettersson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


// Forward declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;


	// TODO remove once Fire() is moved to AimingComponent
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	
	
	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO remove


	double LastFireTime = 0;
};
