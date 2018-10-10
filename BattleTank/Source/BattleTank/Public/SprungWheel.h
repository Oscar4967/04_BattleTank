// Copyright Oscar Pettersson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddDrivingForce(float ForceMagnitude);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SetupConstraint();


	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent * Wheel = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent * MassWheelConstraint = nullptr; //used for Mass - Axel constraint, but changing the name is more work than just changing the name
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent * WheelAxelConstraint = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent * Axel = nullptr;

};
