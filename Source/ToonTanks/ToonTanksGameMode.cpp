// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "ToonTanksPlayerController.h"
#include "Tower.h"
#include "EnemyTank.h"
#include <AIController.h>
#include "Perception/AIPerceptionComponent.h"

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	HandleGameStart();

	
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{

	if(DeadActor == Tank)
	{
		Tank->HandleDestruction();
		
		if(ToonTanksPlayerController)
		{
			ToonTanksPlayerController->SetPlayerEnabledState(false);
		}

		GameOver(false);
		
	} else if(ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
		TowerCount--;
		if(TowerCount == 0)
		{
			GameOver(true);
		}
	}
	else if (AEnemyTank* DestroyedAITank = Cast<AEnemyTank>(DeadActor))
	{
		DestroyedAITank->HandleDestruction();
	}
	
	// Check what type of Actor died. If turret, tally. If Player -> go to lose condition.
}

int32 AToonTanksGameMode::GetTargetTowerCount() const
{
	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);
	return Towers.Num();
}


void AToonTanksGameMode::HandleGameStart()
{
	TowerCount = GetTargetTowerCount();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTanksPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();
	
	if(ToonTanksPlayerController)
	{
		ToonTanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableDelegate = FTimerDelegate::CreateUObject(ToonTanksPlayerController, &AToonTanksPlayerController::SetPlayerEnabledState, true);

		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableDelegate, StartDelay, false);
		
	}
}

