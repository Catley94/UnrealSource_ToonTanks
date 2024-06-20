// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_VehicleShoot.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API UBTT_VehicleShoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_VehicleShoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
