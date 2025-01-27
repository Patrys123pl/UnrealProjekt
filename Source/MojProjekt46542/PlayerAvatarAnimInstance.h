#include "CoreMinimal.h" 
#include "Animation/AnimInstance.h" 
#include "PlayerAvatarAnimInstance.generated.h" 

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	Locomotion = 0, Attack, Trafienie, Die
};
UCLASS()
class MOJPROJEKT46542_API UPlayerAvatarAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAttacking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPlayerState State;
	UFUNCTION(BlueprintCallable)
	void OnStateAnimationEnds();
};