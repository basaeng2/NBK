#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyGameState.generated.h"

class AMyPlayerController;

UCLASS()
class NUMBERBASEBALL_API AMyGameState : public AGameState
{
	GENERATED_BODY()

public:
	AMyGameState();

	TObjectPtr<AMyPlayerController> GetCurrentTurnPlayer() const { return CurrentTurnPlayer; }
	void SetCurrentTurnPlayer(TObjectPtr<AMyPlayerController> NewTurnPlayer);

	float GetTurnStartServerTime() const { return TurnStartServerTime; }
	void SetTurnStartServerTime(float Time) { TurnStartServerTime = Time; }

	float GetTurnTimeLimit() const { return TurnTimeLimit; }
	void SetTurnTimeLimit(float Time) { TurnTimeLimit = Time; }

	void UpdatePlayerTurnUI();

	UFUNCTION()
	float GetRemainingTurnTime() const;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_TurnCount();

	UPROPERTY(Replicated)
	TObjectPtr<AMyPlayerController> CurrentTurnPlayer;

	UPROPERTY(ReplicatedUsing = OnRep_TurnCount)
	int32 TurnCount = 0;

	UPROPERTY(Replicated)
	float TurnStartServerTime;

	UPROPERTY(Replicated)
	float TurnTimeLimit;
};