// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"

void ATower::BeginPlay()
{
    Super::BeginPlay();
	
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	DrawDebugSphere(
		GetWorld(),
		GetActorLocation(),
		FireRange,
		12,
		FColor::Red,
		true,
		-1.f
	);

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Find the distance to the tank
	if(Tank)
	{
		if(InFireRange())
		{
			RotateTurret(Tank->GetActorLocation());
		}
	}
}

bool ATower::InFireRange() const
{
	if(Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if(Distance <= FireRange)
		{
			//Hello
			return true;
		}
	}
	return false;
}

void ATower::CheckFireCondition()
{
	if(InFireRange())
	{
		//Fire
		Fire();
	}
}

void ATower::OnTakeAnyDamage()
{
	UE_LOG(LogTemp, Warning, TEXT("DAMAGE %s"), *GetName());
}


