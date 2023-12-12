// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = ProjectileMesh;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->InitialSpeed = 1300.f;
	ProjectileMovementComponent->MaxSpeed = 1300.f;

	TrailParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle Trail"));
	TrailParticles->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);

	if(LaunchSound) UGameplayStatics::PlaySoundAtLocation(this, LaunchSound, GetActorLocation());
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* thisComp, AActor* ActorHit, UPrimitiveComponent* CompHit, FVector NormalImpulse, const FHitResult &Hit)
{

	AActor* MyOwner = GetOwner();
	if(MyOwner == nullptr)
	{
		Destroy();
		return;
	}
	if(ActorHit && ActorHit != this && ActorHit != MyOwner)
	{		
		// UE_LOG(LogTemp, Warning, TEXT("HIT"));
		// UE_LOG(LogTemp, Warning, TEXT("HIT COMP: %s"), *thisComp->GetName());
		// UE_LOG(LogTemp, Warning, TEXT("OTHER ACTOR: %s"), *ActorHit->GetName());
		// UE_LOG(LogTemp, Warning, TEXT("OTHER COMP: %s"), *CompHit->GetName());
		UGameplayStatics::ApplyDamage(ActorHit, Damage, MyOwner->GetInstigatorController(), this, UDamageType::StaticClass());
		if(HitParticles)
		{
			UGameplayStatics::SpawnEmitterAtLocation(this, HitParticles, GetActorLocation(), GetActorRotation());
		}
		
		if(HitSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
		}
		
		if(HitCameraShakeClass)
		{
			GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(HitCameraShakeClass);
		}
		
	}
	Destroy();

}

