// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTank.h"
#include <AIController.h>
#include "Perception/AIPerceptionComponent.h"

#include "BehaviorTree/BehaviorTreeComponent.h"

void AEnemyTank::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	// Hide Tank
	// Delete Tank
    // Get the AI controller
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController)
    {
        // Disable the AI controller
        AIController->SetActorTickEnabled(false);
        UE_LOG(LogTemp, Log, TEXT("Deactivating AIControllerTick"));
    	AIController->BrainComponent->StopLogic("Reason");
        UE_LOG(LogTemp, Log, TEXT("Deactivating BrainComponent"));
    	
    	
        // Optionally disable perception component if it exists
        UAIPerceptionComponent* PerceptionComponent = AIController->FindComponentByClass<UAIPerceptionComponent>();
        if (PerceptionComponent)
        {
            PerceptionComponent->SetActive(false);
            UE_LOG(LogTemp, Log, TEXT("Deactivating Perception Component"));
        }
    }
}