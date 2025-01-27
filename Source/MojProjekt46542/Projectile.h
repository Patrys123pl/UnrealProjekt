// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS(Blueprintable)
class MOJPROJEKT46542_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	float Speed = 100.0f;
	float Lifespan = 5.0f;
	float Damage = 10.0f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float _LifeCountingDown;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
