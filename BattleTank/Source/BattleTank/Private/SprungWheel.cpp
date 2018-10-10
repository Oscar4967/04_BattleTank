// Copyright Oscar Pettersson

#include "SprungWheel.h"


// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("MassWheelConstraint"));
	SetRootComponent(MassWheelConstraint);

	Axel = CreateDefaultSubobject<USphereComponent>(FName("Axel"));
	Axel->SetupAttachment(MassWheelConstraint);

	WheelAxelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("WheelAxelConstraint"));
	WheelAxelConstraint->SetupAttachment(Axel);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->SetupAttachment(Axel);

	
	

	

	/*MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("MassWheelConstraint"));
	SetRootComponent(MassWheelConstraint);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->SetupAttachment(MassWheelConstraint);*/
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	SetupConstraint();
	
}

void ASprungWheel::SetupConstraint()
{
	if (!GetAttachParentActor()) { return; }
	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot) { return; }
	MassWheelConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axel, NAME_None);
	if (!Axel) { return; }
	WheelAxelConstraint->SetConstrainedComponents(Axel, NAME_None, Wheel, NAME_None);
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASprungWheel::AddDrivingForce(float ForceMagnitude)
{
	Wheel->AddForce(Axel->GetForwardVector() * ForceMagnitude);
}

