#include "DefenseTower.h"

// Konstruktor
ADefenseTower::ADefenseTower()
{
	PrimaryActorTick.bCanEverTick = true;

	// Tworzenie i przypisanie komponentów
	_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(_BoxComponent);

	_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	_MeshComponent->SetupAttachment(_BoxComponent);

	// Inicjalizacja zmiennych
	_HealthPoints = HealthPoints = 100;
	ShellDefense = 2;
	AttackRange = 15.0f;
	ReloadInterval = 1.0f;
	_ReloadCountingDown = 0.0f;
}

// Funkcja wywo³ywana przy starcie gry
void ADefenseTower::BeginPlay()
{
	Super::BeginPlay();
}

// Funkcja wywo³ywana co klatkê
void ADefenseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Licznik prze³adowania
	if (_ReloadCountingDown > 0.0f)
	{
		_ReloadCountingDown -= DeltaTime;
	}
}

// Implementacja funkcji
int ADefenseTower::GetHealthPoints() const
{
	return _HealthPoints;
}

bool ADefenseTower::IsDestroyed() const
{
	return (_HealthPoints <= 0);
}

bool ADefenseTower::CanFire() const
{
	return (_ReloadCountingDown <= 0.0f);
}

void ADefenseTower::Fire()
{
	if (CanFire())
	{
		_ReloadCountingDown = ReloadInterval;
		UE_LOG(LogTemp, Log, TEXT("DefenseTower: Fire!"));
	}
}

void ADefenseTower::Hit(int Damage)
{
	_HealthPoints -= FMath::Max(0, Damage - ShellDefense); // Uszkodzenia z uwzglêdnieniem pancerza
	if (_HealthPoints <= 0)
	{
		DestroyProcess();
	}
}

void ADefenseTower::DestroyProcess()
{
	UE_LOG(LogTemp, Log, TEXT("DefenseTower: Destroyed!"));
	Destroy();
}