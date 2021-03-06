
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subject.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Projectile.generated.h"


UCLASS()
class UE4PANZER_API AProjectile : public AActor, public Subject
{
	GENERATED_BODY()

private:
	void Unify(FVector &v);

public:
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	UProjectileMovementComponent* ProjectileMovement = nullptr;

	void LaunchProjectile(FVector Direction, bool ReLaunch = false);

	UPROPERTY(VisibleAnywhere, Category = "Components")

	UStaticMeshComponent* CollisionMesh = nullptr;

	void NotifyObservers() override;

	float LaunchSpeed = 10000;

	//void Tick(float DeltaTime) override;
};

//extern std::vector<Observer*> PotentialObservers;