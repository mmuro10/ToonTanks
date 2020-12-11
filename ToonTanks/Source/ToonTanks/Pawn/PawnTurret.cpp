// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnTurret::CheckFireCondition()
{
	//if player == null || is Dead then bail!!
	if (!PlayerPawn) { return; }

	//if player IS in range then FIRE!!
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		// FIRE@
		UE_LOG(LogTemp, Warning, TEXT("Check Fire Condition is checked"))
	}
	
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn) 
	{
		return 0.0f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());

 
}