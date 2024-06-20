// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTank.h"

void AEnemyTank::HandleDestruction()
{
	Super::HandleDestruction();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	// Hide Tank
	// Delete Tank
}