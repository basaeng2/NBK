#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyGameState.generated.h"

UCLASS()
class NUMBERBASEBALL_API AMyGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	AMyGameState();
		
	APlayerController* GetCurrentTurnPlayer() const { return CurrentTurnPlayer; }
	void SetCurrentTurnPlayer(APlayerController* NewTurnPlayer);

	float GetCurrentTurnTimeRemaining() { return CurrentTurnTimeRemaining; }
	void SetCurrentTurnTimeRemaining(float time) { this->CurrentTurnTimeRemaining = time; }

private:
	UPROPERTY(Replicated)
	APlayerController* CurrentTurnPlayer;

	void OnCurrentTurnPlayerChanged();

	UPROPERTY(Replicated)
	float CurrentTurnTimeRemaining;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};