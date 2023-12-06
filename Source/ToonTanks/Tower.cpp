// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

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
}

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find the distance to the tank


	if(Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		
		
		
	    // Check to see if the Tank is in Range
		if(Distance <= FireRange)
		{
			RotateTurret(Tank->GetActorLocation());
		}
	    // If in range, rotate turrent toward tank
	}
	
}


