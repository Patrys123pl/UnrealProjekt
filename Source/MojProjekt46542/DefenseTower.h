#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DefenseTower.generated.h"

UCLASS(Blueprintable)
class MOJPROJEKT46542_API ADefenseTower : public AActor
{
	GENERATED_BODY()

public:
	// Konstruktor
	ADefenseTower();

	// Publiczne zmienne widoczne w edytorze Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	int HealthPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	int ShellDefense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	float ReloadInterval;

	// Funkcje dostêpne w Blueprint
	UFUNCTION(BlueprintCallable, Category = "mojprojekt46542|Defense Tower")
	int GetHealthPoints() const;

	UFUNCTION(BlueprintCallable, Category = "mojprojekt46542|Defense Tower")
	bool IsDestroyed() const;

	UFUNCTION(BlueprintCallable, Category = "mojprojekt46542|Defense Tower")
	bool CanFire() const;

	UFUNCTION(BlueprintCallable, Category = "mojprojekt46542|Defense Tower")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "mojprojekt46542|Defense Tower")
	void Hit(int Damage);

protected:
	// Zmienne prywatne
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower Components", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* _BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* _MeshComponent;

	// Aktualne punkty zdrowia
	int _HealthPoints;

	// Licznik prze³adowania
	float _ReloadCountingDown;

	// Proces niszczenia wie¿y
	void DestroyProcess();

	// Wywo³ywane przy starcie gry
	virtual void BeginPlay() override;

public:
	// Wywo³ywane co klatkê
	virtual void Tick(float DeltaTime) override;
};