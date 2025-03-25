#include "MyGameState.h"
#include "Net/UnrealNetwork.h"
#include "MyGameMode.h"
#include "MyPlayerController.h"

AMyGameState::AMyGameState() { }

void AMyGameState::SetCurrentTurnPlayer(APlayerController* NewTurnPlayer)
{
    if (!HasAuthority())
    {
        ensureAlways(false);
        return;
    }

    CurrentTurnPlayer = NewTurnPlayer;

    if (GetNetMode() != NM_DedicatedServer)
    {
        OnCurrentTurnPlayerChanged();
    }
}

void AMyGameState::OnCurrentTurnPlayerChanged()
{
    for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
    {
        AMyPlayerController* PC = Cast<AMyPlayerController>(*It);
        if (!PC) continue;

        if (PC == CurrentTurnPlayer)
        {
            PC->ClientSetMyTurn();
        }
        else
        {
            PC->ClientSetOtherTurn();
        }
    }
}

void AMyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMyGameState, CurrentTurnPlayer);
    DOREPLIFETIME(AMyGameState, CurrentTurnTimeRemaining);
}