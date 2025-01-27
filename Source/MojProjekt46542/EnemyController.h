#pragma once
#include "CoreMinimal.h" 
#include "AIController.h" 
#include "EnemyController.generated.h" 

UCLASS()
class MOJPROJEKT46542_API AEnemyController : public AAIController
{
	GENERATED_BODY()
	public:
	void MakeAttackDecision(APawn* targetPawn);
};
