// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector LookAtTarget)
{

	FVector LookAtTargetClean = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();
	FRotator TurretRotation = FVector(LookAtTargetClean - StartLocation).Rotation();

	//Update the Turret mesh rotation to face towards the lookat target passed in from child classes
	TurretMesh->SetWorldRotation(TurretRotation);
}

void APawnBase::Fire()
{
	//Get projectile spawn point location && Rotation -> Spawn Projectile class at location firing towards rotation
	UE_LOG(LogTemp, Warning, TEXT("Check Fire Condition is checked"));
}

void APawnBase::HandleDestruction()
{
	// --- Universal fnctionality --
	//play death effects particles, sound and camera shake

	//--- Child overrides ---
	//--- PawnTurret - Inform GameMode Turret died - Tehn Destroy() self.

	//-- PawnTank - Inform GameMode player died -> Then Hide() all Components && Stop movement input.
}

