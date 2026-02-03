#include "MyGameMode.h"
#include "MyGameState.h"
#include "MyPlayerController.h"

AMyGameMode::AMyGameMode()
{
    PlayerControllerClass = AMyPlayerController::StaticClass();
    GameStateClass = AMyGameState::StaticClass();
}

void AMyGameMode::Ready()
{
    if (GetReadyCount() == PlayerNum)
    {
        StartGame();
    }
}

void AMyGameMode::CheckAnswer(AMyPlayerController* PlayerController, const FString& InputNumberStr)
{
    if (!PlayerController) { return; }

    int32 Strike = 0;
    int32 Ball = 0;

    if (InputNumberStr.Len() != DIGITS_COUNT || AnswerNumber.Len() != DIGITS_COUNT)
    {
        return;
    }

    for (int32 i = 0; i < DIGITS_COUNT; i++)
    {
        if (InputNumberStr[i] == AnswerNumber[i])
        {
            Strike++;
        }
        else if (AnswerNumber.Contains(FString(1, &InputNumberStr[i])))
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

void AMyGameMode::RequestRestartGame(APlayerController* RequestingPC)
{
    if (!PlayerControllers.Contains(RequestingPC)) return;

    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        AMyPlayerController* PC = Cast<AMyPlayerController>(*It);

        check(PC);
        PC->ClientResettingButtons();

        NotifyClientReadyForRestart(PC);
    }
}

void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();
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

void AMyGameMode::StartGame()
{
    AnswerNumber = GenerateRandomNumber(4);

    PickRandomFirstTurnPlayer();

    StartTurnTimer();
}

FString AMyGameMode::GenerateRandomNumber(const int32 DigitCount)
{
    TArray<int32> Nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    FString ResultNumber;
    int32 LastIndex = Nums.Num() - 1;
    for (int32 i = 0; i < DigitCount; i++)
    {
        int32 RandIndex = FMath::RandRange(0, LastIndex);
        ResultNumber.AppendInt(Nums[RandIndex]);
        Nums.Swap(RandIndex, LastIndex);
        LastIndex--;
    }

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            5.0f,
            FColor::Yellow,
            FString::Printf(TEXT("Generated Number: %s"), *ResultNumber)
        );
    }

    return ResultNumber;
}

void AMyGameMode::PickRandomFirstTurnPlayer()
{
    if (PlayerControllers.Num() < PlayerNum) return;

    int32 RandomIndex = FMath::RandRange(0, PlayerControllers.Num() - 1);

    AMyGameState* GS = GetGameState<AMyGameState>();
    if (GS)
    {
        GS->SetCurrentTurnPlayer(PlayerControllers[RandomIndex]);
    }
}

void AMyGameMode::StartTurnTimer()
{
    GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle);

    AMyGameState* GS = Cast<AMyGameState>(GameState);
    if (GS)
    {
        GS->SetTurnStartServerTime(GS->GetServerWorldTimeSeconds());
        GS->SetTurnTimeLimit(TurnTimeLimit);
    }

    GetWorld()->GetTimerManager().SetTimer(
        TurnTimerHandle,
        this,
        &AMyGameMode::HandleTurnTimeout,
        TurnTimeLimit,
        false
    );
}

void AMyGameMode::HandleTurnTimeout()
{
    GetWorld()->GetTimerManager().ClearTimer(TurnTimerHandle);

    NextTurn();
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

void AMyGameMode::NotifyClientReadyForRestart(AMyPlayerController* PC)
{
    RestartReadyCount++;

    if (RestartReadyCount >= PlayerControllers.Num())
    {
        RestartReadyCount = 0;

        StartGame();
    }
}