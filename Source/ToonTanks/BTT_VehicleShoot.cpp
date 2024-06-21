// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_VehicleShoot.h"
#include "EnemyTank.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <Kismet/GameplayStatics.h>

#include "Tank.h"

UBTT_VehicleShoot::UBTT_VehicleShoot()
{
    NodeName = "Shoot";
}

EBTNodeResult::Type UBTT_VehicleShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    AEnemyTank* AITank = Cast<AEnemyTank>(OwnerComp.GetAIOwner()->GetPawn());
    if (AITank == nullptr)
    {
        return EBTNodeResult::Failed;
    }
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn != nullptr)
    {
        //TODO: Check if PlayerPawn is dead, then return EBTNodeResult::Failed;
        ATank* Tank = Cast<ATank>(PlayerPawn);
        if(Tank->bAlive)
        {
            FVector PlayerLocation = PlayerPawn->GetActorLocation();
            AITank->RotateTurret(PlayerLocation);
            AITank->Fire();
            UE_LOG(LogTemp, Log, TEXT("Tank is alive"));
        }
    }
    return EBTNodeResult::Succeeded;
}
