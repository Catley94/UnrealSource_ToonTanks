// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "EnemyTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AEnemyTank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	void HandleDestruction();

};
