// Copyright Oscar Pettersson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	// Returns current health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

public:
	FTankDelegate OnDeath;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetInitialHealth();

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	// Called by the engine when actor damage is taken
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 MaxHealth = 50;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 CurrentHealth;


};
