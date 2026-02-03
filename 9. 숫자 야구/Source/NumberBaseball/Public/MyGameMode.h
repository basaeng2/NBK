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

	int32 GetReadyCount() const { return ReadyCount; }

	int32 GetPlayerNum() const { return PlayerNum; }

	void Ready();

	void CheckAnswer(AMyPlayerController* PlayerController, const FString& InputNumberString);

	void RequestRestartGame(APlayerController* RequestingPC);

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

private:
	void StartGame();

	FString GenerateRandomNumber(const int32 DigitCount);

	void PickRandomFirstTurnPlayer();

	void StartTurnTimer();

	void HandleTurnTimeout();

	void NextTurn();

	void NotifyClientReadyForRestart(AMyPlayerController* PC);

	TArray<TObjectPtr<AMyPlayerController>> PlayerControllers;

	int32 PlayerNum = 0;

	static constexpr int32 DIGITS_COUNT = 4;

	FString AnswerNumber;

	static constexpr float TurnTimeLimit = 30.0f;

	FTimerHandle TurnTimerHandle;

	int32 RestartReadyCount = 0;
};