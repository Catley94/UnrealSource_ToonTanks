// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void HandleDestruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

		
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnTakeAnyDamage();

	APlayerController* GetTankPlayerController() const { return TankPlayerController; }

	bool bAlive = true;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Config")
	float CameraDistance = 300.f;

	UPROPERTY(EditAnywhere, Category = "Config")
	float TankSpeed = 400.f;
	
	UPROPERTY(EditAnywhere, Category = "Config")
	float TankRotationSpeed = 100.f;
	
	void Move(float Value);
	
	void Turn(float Value);

	APlayerController* TankPlayerController;
	
};
