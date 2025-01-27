#pragma once
#include "CoreMinimal.h" 
#include "GameFramework/Character.h" 
#include "Enemy.generated.h" 

UCLASS()

class MOJPROJEKT46542_API AEnemy : public ACharacter
{
	GENERATED_BODY()
public:
	AEnemy();
	UPROPERTY(EditAnywhere, Category = "Enemy Params")
	int HealthPoints = 100;
	UPROPERTY(EditAnywhere, Category = "Enemy Params")
	float Strength = 5.0;
	UPROPERTY(EditAnywhere, Category = "Enemy Params")
	float Armor = 1;
	UPROPERTY(EditAnywhere, Category = "Enemy Params")
	float AttackRange = 200.0f;
	UPROPERTY(EditAnywhere, Category = "Enemy Params")
	float AttackInterval = 3.0f;
protected:
	virtual void BeginPlay() override;
	int _HealthPoints;
	float _AttackCountingDown;
	APawn* _chasedTarget = nullptr;
public:
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Pangaea|Enemy", meta = (DisplayName = "Get HP"))
	int GetHealthPoints();
	UFUNCTION(BlueprintCallable, Category = "Pangaea|Enemy")
	bool IsKilled();
	UFUNCTION(BlueprintCallable, Category = "Pangaea|Enemy")
	bool CanAttack();
	UFUNCTION(BlueprintCallable, Category = "Pangaea|Enemy")
	void Chase(APawn* targetPawn);
	void Attack();
	void Hit(int damage);
	void DieProcess();
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPawnSensingComponent* PawnSensingComponent;
};