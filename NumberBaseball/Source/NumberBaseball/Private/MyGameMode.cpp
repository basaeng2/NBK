#include "MyGameMode.h"
#include "MyGameState.h"
#include "MyPlayerController.h"

AMyGameMode::AMyGameMode()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();
	GameStateClass = AMyGameState::StaticClass();
}

void AMyGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    if (AMyPlayerController* PC = Cast<AMyPlayerController>(NewPlayer))
    {
        PlayerControllers.Add(PC);
        PlayerNum++;
    }
}

void AMyGameMode::Ready()
{
    if (GetReadyCount() == PlayerNum)
    {
        StartGame();
    }
}

void AMyGameMode::StartGame()
{
    ServerNumber = GenerateRandomNumber(4);

    PickRandomFirstTurnPlayer();

    StartTurnTimer();
}

FString AMyGameMode::GenerateRandomNumber(const int32 DigitCount)
{
    TArray<int32> Digits;
    while (Digits.Num() < DigitCount)
    {
        int32 RandDigit = FMath::RandRange(1, 9);
        if (!Digits.Contains(RandDigit))
        {
            Digits.Add(RandDigit);
        }
    }

    FString Result;
    for (int32 Num : Digits)
    {
        Result.AppendInt(Num);
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            5.0f,
            FColor::Yellow,
            FString::Printf(TEXT("Generated Number: %s"), *Result)
        );
    }

    return Result;
}

void AMyGameMode::PickRandomFirstTurnPlayer()
{
    if (PlayerControllers.Num() < PlayerNum) return;

    int32 RandomIndex = FMath::RandRange(0, PlayerControllers.Num() - 1);

    AMyGameState* GS = GetGameState <AMyGameState>();
    if (GS)
    {
        GS->SetCurrentTurnPlayer(PlayerControllers[RandomIndex]);
    }
}

void AMyGameMode::StartTurnTimer()
{
    GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle);
    GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

    AMyGameState* GS = Cast<AMyGameState>(GameState);
    if (GS)
    {
        GS->SetCurrentTurnTimeRemaining(TurnTimeLimit);
    }

    GetWorld()->GetTimerManager().SetTimer(
        TurnTimerHandle,
        this,
        &AMyGameMode::HandleTurnTimeout,
        TurnTimeLimit,
        false
    );

    GetWorld()->GetTimerManager().SetTimer(
        UpdateTimerHandle,
        this,
        &AMyGameMode::UpdateTurnTimeRemaining,
        0.1f,
        true
    );
}

void AMyGameMode::CheckAnswer(AMyPlayerController* PlayerController, const FString& InputNumberStr)
{
       if (!PlayerController) { return; }

    int32 Strike = 0;
    int32 Ball = 0;

    if (InputNumberStr.Len() != DIGITS_COUNT || ServerNumber.Len() != DIGITS_COUNT)
    {
        return;
    }

    for (int32 i = 0; i < DIGITS_COUNT; i++)
    {
        if (InputNumberStr[i] == ServerNumber[i])
        {
            Strike++;
        }
        else if (ServerNumber.Contains(FString(1, &InputNumberStr[i])))
        {
            Ball++;
        }
    }

    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        if (AMyPlayerController* PC = Cast<AMyPlayerController>(*It))
        {
            PC->ClientReceiveResult(InputNumberStr, Strike, Ball);
        }
    }

    if (Strike == DIGITS_COUNT)
    {
        GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle);
        GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

        PlayerController->ClientOnGameWin();

        for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
        {
            if (AMyPlayerController* PC = Cast<AMyPlayerController>(*It))
            {
                if (PC != PlayerController)
                {
                    PC->ClientOnGameLose();
                }
            }
        }
    }
    else
    {
        NextTurn();
    }
}

void AMyGameMode::HandleTurnTimeout()
{
    GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle);
    GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);

    NextTurn();
}

void AMyGameMode::UpdateTurnTimeRemaining()
{
    AMyGameState* GS = Cast<AMyGameState>(GameState);
    if (!GS) return;

    if (!GetWorld()->GetTimerManager().IsTimerActive(TurnTimerHandle))
    {
        GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);
        return;
    }

    float RemainingTime = GetWorld()->GetTimerManager().GetTimerRemaining(TurnTimerHandle);

    if (RemainingTime < 0.0f || RemainingTime > TurnTimeLimit || !FMath::IsFinite(RemainingTime))
    {
        RemainingTime = TurnTimeLimit;
    }

    GS->SetCurrentTurnTimeRemaining(RemainingTime);

    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        AMyPlayerController* PC = Cast<AMyPlayerController>(*It);
        if (PC)
        {
            PC->ClientUpdateTurnTime(GS->GetCurrentTurnTimeRemaining());
        }
    }
}

void AMyGameMode::NextTurn()
{
    if (PlayerControllers.Num() == 0) return;

    AMyGameState* GS = GetGameState<AMyGameState>();
    if (!GS) return;

    int32 CurrentIndex = PlayerControllers.IndexOfByKey(GS->GetCurrentTurnPlayer());
    int32 NextIndex = (CurrentIndex + 1) % PlayerControllers.Num();
    GS->SetCurrentTurnPlayer(PlayerControllers[NextIndex]);

    StartTurnTimer();
}

void AMyGameMode::RequestRestartGame(APlayerController* RequestingPC)
{
    if (!PlayerControllers.Contains(RequestingPC)) return;

    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        AMyPlayerController* PC = Cast<AMyPlayerController>(*It);
        if (PC)
        {
            PC->ClientResettingbuttons();
        }
    }

    StartGame();
}

void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();
}