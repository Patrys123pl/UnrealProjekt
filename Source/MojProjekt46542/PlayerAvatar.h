// Fill out your copyright notice in the Description page of Project Settings.



#pragma once

#include "CoreMinimal.h" 
#include "GameFramework/Character.h" 
#include "GameFramework/SpringArmComponent.h" 
#include "Camera/CameraComponent.h" 
#include "PlayerAvatar.generated.h"

UCLASS(Blueprintable)
class MOJPROJEKT46542_API APlayerAvatar : public ACharacter
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "mojprojekt46542|PlayerCharacter", meta = (DisplayName = "Get HP"))
	int GetHealthPoints();
	UFUNCTION(BlueprintCallable,
		Category = "mojprojekt46542|PlayerCharacter")
	bool IsKilled();
	UFUNCTION(BlueprintCallable, Category = "mojprojekt46542|PlayerCharacter")
	bool CanAttack();

	FORCEINLINE USpringArmComponent* GetSringArmComponent() const
	{
		return _springArmComponent;
	}
	FORCEINLINE UCameraComponent* GetCameraComponent() const
	{
		return _cameraComponent;
	}

public:
	// Sets default values for this character's properties
	APlayerAvatar();
	int HealthPoints = 500;
	float Strength = 10;
	float Armer = 3;
	float AttackRange = 6.0f;
	float AttackInterval = 1.2f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int _HealthPoints;
	float _AttackCountingDown;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int GetHealthPoints();
	bool IsKilled();
	bool CanAttack();
	void Attack();
	void Hit(int damage);
protected:
	void DieProcess();


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* _springArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* _cameraComponent;

};
