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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 VisibleAnywhereInt32 = 12;

	UPROPERTY(EditAnywhere)
	int32 EditAnywhereInt32 = 32;
	
	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt32 = 42;
	
	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt32 = 52;

	UFUNCTION(BlueprintCallable)
	void Fire();

	void HandleDestruction();

	UFUNCTION(BlueprintCallable)
	void RotateTurret(FVector LookAtTarget);

	UPROPERTY(BlueprintReadWrite, Category="Status")
	bool bAlive = true;

protected:


	
	
private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Components")
	class UCapsuleComponent* CapsuleComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  meta = (AllowPrivateAccess = "true"), Category = "Components")
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  meta = (AllowPrivateAccess = "true"), Category = "Components")
	UStaticMeshComponent* TurretMesh;

	//meta = (AllowPrivateAccess = "true") is not needed but here for reference of learning purposes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,  meta = (AllowPrivateAccess = "true"), Category = "Components")
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
	
};
