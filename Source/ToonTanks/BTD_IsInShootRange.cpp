// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsInShootRange.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTD_IsInShootRange::UBTD_IsInShootRange()
{

}

bool UBTD_IsInShootRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
    // Get the AI controller and its pawn
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController == nullptr)
    {
        return false;
    }

    APawn* AIPawn = AIController->GetPawn();
    if (AIPawn == nullptr)
    {
        return false;
    }

    // Get the blackboard component
    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (BlackboardComp == nullptr)
    {
        return false;
    }

    // Get the target actor from the blackboard
    UObject* TargetObject = BlackboardComp->GetValueAsObject(TargetKey.SelectedKeyName);
    AActor* TargetActor = Cast<AActor>(TargetObject);
    if (TargetActor == nullptr)
    {
        return false;
    }

    // Calculate the distance between the AI pawn and the target actor
    float Distance = FVector::Dist(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());

    // Check if the distance is within the specified range
    return Distance <= Range;
}