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
        if(Cast<ATank>(PlayerPawn)->bAlive)
        {
            AITank->RotateTurret(PlayerPawn->GetActorLocation());
            AITank->Fire();
        }
    }
    return EBTNodeResult::Succeeded;
}
