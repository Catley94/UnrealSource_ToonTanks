// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(VisibleAnywhere)
	int32 VisibleAnywhereInt32 = 12;

	UPROPERTY(EditAnywhere)
	int32 EditAnywhereInt32 = 32;
	
	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt32 = 42;
	
	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt32 = 52;

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* TurretMesh;
	
	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Config")
	float TankSpeed = 400.f;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
