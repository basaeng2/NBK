#include "MyGameState.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"

AMyGameState::AMyGameState()
{
    NetUpdateFrequency = 20.0f;
}

void AMyGameState::SetCurrentTurnPlayer(TObjectPtr<AMyPlayerController> NewTurnPlayer)
{
    if (!HasAuthority())
    {
        ensureAlways(false);
        return;
    }

    CurrentTurnPlayer = NewTurnPlayer;

    TurnCount++;

    UpdatePlayerTurnUI();
}

void AMyGameState::UpdatePlayerTurnUI()
{
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        AMyPlayerController* PC = Cast<AMyPlayerController>(*It);
        if (!PC) continue;

        if (PC == CurrentTurnPlayer)
        {
            PC->SetMyTurn();
        }
        else
        {
            PC->SetOtherTurn();
        }
    }
}

float AMyGameState::GetRemainingTurnTime() const
{
    if (TurnTimeLimit <= 0.f) return 0.f;

    float Elapsed = GetServerWorldTimeSeconds() - TurnStartServerTime;
    float RemainingTurnTime = FMath::Max(0.f, TurnTimeLimit - Elapsed);
    return RemainingTurnTime;
}

void AMyGameState::OnRep_TurnCount()
{
    UpdatePlayerTurnUI();
}

void AMyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AMyGameState, CurrentTurnPlayer);
    DOREPLIFETIME(AMyGameState, TurnCount);
    DOREPLIFETIME(AMyGameState, TurnStartServerTime);
    DOREPLIFETIME(AMyGameState, TurnTimeLimit);
}