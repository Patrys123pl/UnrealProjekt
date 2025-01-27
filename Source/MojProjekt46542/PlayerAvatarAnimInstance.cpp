#include "PlayerAvatarAnimInstance.h" #include "PlayerAvatar.h"
void UPlayerAvatarAnimInstance::OnStateAnimationEnds()
{
	if (State == EPlayerState::Attack)
	{
		State = EPlayerState::Locomotion;
	}
	else
	{
		auto ownerActor = this->GetOwningActor();
		auto playerAvatar = Cast<APlayerAvatar>(ownerActor);
		if (playerAvatar == nullptr)
		{
			Return;
		}
		if (State == EPlayerState::Hit)
		{
			if (playerAvatar->GetHealthPoints() > 0.0f)
			{
				State = EPlayerState::Locomotion;
			}
			else
			{
				State = EPlayerState::Die;
			}
		}
		else if (State == EPlayerState::Die)
		{
			//�
		}
	}
}