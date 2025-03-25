#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyPlayerController.h"
#include "MyGameMode.generated.h"

UCLASS()
class NUMBERBASEBALL_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AMyGameMode();

	static int32 GetDigitsCount() { return DIGITS_COUNT; }

	int32 ReadyCount = 0;

	int32 GetReadyCount() { return ReadyCount; }

	int32 GetPlayerNum() { return PlayerNum; }

	void Ready();

	void StartGame();

	void CheckAnswer(AMyPlayerController* PlayerController, const FString& InputNumberString);

	void RequestRestartGame(APlayerController* RequestingPC);

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	FString GenerateRandomNumber(const int32 DigitCount);

	void PickRandomFirstTurnPlayer();

	void NextTurn();

private:
	TArray<AMyPlayerController*> PlayerControllers;

	int32 PlayerNum = 0;

	static const int32 DIGITS_COUNT = 4;

	FString ServerNumber;

	UPROPERTY()
	float TurnTimeLimit = 10.0f;

	FTimerHandle TurnTimerHandle;
	FTimerHandle UpdateTimerHandle;

	void StartTurnTimer();

	void HandleTurnTimeout();

	void UpdateTurnTimeRemaining();
};
