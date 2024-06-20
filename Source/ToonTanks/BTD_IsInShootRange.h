// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BTD_IsInShootRange.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API UBTD_IsInShootRange : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()
	
public:
    UBTD_IsInShootRange();

protected:
    /** Called when the node is asked to evaluate its condition */
    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

    /** The range within which the object needs to be */
    UPROPERTY(EditAnywhere, Category = "Condition")
    float Range;

    /** The blackboard key selector for the target object */
    UPROPERTY(EditAnywhere, Category = "Blackboard")
    struct FBlackboardKeySelector TargetKey;
};
