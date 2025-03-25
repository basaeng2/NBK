#include "MyPlayerController.h"
#include "MyGameMode.h"
#include "Widget_Main.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
	: HUDWidgetClass(nullptr),
	HUDWidgetInstance(nullptr)
{}

void AMyPlayerController::ServerSendReadyValue_Implementation(bool IsReady)
{
	if (IsReady)
	{
		AMyGameMode* GM = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
		{
			GM->ReadyCount++;
			UE_LOG(LogTemp, Warning, TEXT("Received value: %d"), GM->ReadyCount);

			if (HasAuthority())
			{
				if (GM->ReadyCount == 2)
				{
					GM->Ready();
				}
			}
		}
	}
}

void AMyPlayerController::ClientSetMyTurn_Implementation()
{
	UWidget_Main* MainWidget = Cast<UWidget_Main>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->SetAllButtonsEnabled(true);
		MainWidget->ClearGuessNumberTextMessage();
		MainWidget->ShowSIgnMessage(TEXT("내 턴입니다"));
	}
}

void AMyPlayerController::ClientSetOtherTurn_Implementation()
{
	UWidget_Main* MainWidget = Cast<UWidget_Main>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->SetAllButtonsEnabled(false);
		MainWidget->ClearGuessNumberTextMessage();
		MainWidget->ShowSIgnMessage(TEXT("상대방 턴입니다"));
	}
}

void AMyPlayerController::ServerSubmitGuess_Implementation(const FString& InputNumber)
{
	if (GetWorld())
	{
		AMyGameMode* GM = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
		if (GM)
		{
			GM->CheckAnswer(this, InputNumber);
		}
	}
}

void AMyPlayerController::ClientReceiveResult_Implementation(const FString& InputNumber, int32 Strike, int32 Ball)
{
	UWidget_Main* MainWidget = Cast<UWidget_Main>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowJudgementResult(InputNumber, Strike, Ball);
	}
}

void AMyPlayerController::ClientUpdateTurnTime_Implementation(float RemainingTime)
{
	UWidget_Main* MainWidget = Cast<UWidget_Main>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->UpdateTurnTimeDisplay(RemainingTime);
	}
}

void AMyPlayerController::ClientOnGameWin_Implementation()
{
	UWidget_Main* MainWidget = Cast<UWidget_Main>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowGameWinMessage();
		MainWidget->SetAllButtonsEnabled(false);
		MainWidget->SetRestartButtonVisible(true);
	}
}

void AMyPlayerController::ClientOnGameLose_Implementation()
{
	UWidget_Main* MainWidget = Cast<UWidget_Main>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ShowGameLoseMessage();
		MainWidget->SetAllButtonsEnabled(false);
		MainWidget->SetRestartButtonVisible(true);
	}
}

void AMyPlayerController::ServerRequestRestart_Implementation()
{
	AMyGameMode* GM = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
	if (GM)
	{
		GM->RequestRestartGame(this);
	}
}

void AMyPlayerController::ClientResettingbuttons_Implementation()
{
	UWidget_Main* MainWidget = Cast<UWidget_Main>(HUDWidgetInstance);
	if (MainWidget)
	{
		MainWidget->ResetUI();
	}
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if(IsLocalController())
	{
		CreateWidgetOnViewport();
		ServerSendReadyValue(true);
	}
}

void AMyPlayerController::CreateWidgetOnViewport()
{
	if (HUDWidgetClass)
	{
		HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance)
		{
			HUDWidgetInstance->AddToViewport();
		}
	}
}