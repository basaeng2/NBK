#include "MyPlayerController.h"
#include "MyGameMode.h"
#include "Widget_Main.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
	: HUDWidgetClass(nullptr),
	HUDWidgetInstance(nullptr)
{}

void AMyPlayerController::SetMyTurn()
{
	if (!IsLocalController()) return;

	check(HUDWidgetInstance);

	HUDWidgetInstance->SetAllButtonsEnabled(true);
	HUDWidgetInstance->ClearGuessNumberTextMessage();
	HUDWidgetInstance->ShowSignMessage(TEXT("내 턴입니다"));
}

void AMyPlayerController::SetOtherTurn()
{
	if (!IsLocalController()) return;

	check(HUDWidgetInstance);

	HUDWidgetInstance->SetAllButtonsEnabled(false);
	HUDWidgetInstance->ClearGuessNumberTextMessage();
	HUDWidgetInstance->ShowSignMessage(TEXT("상대방 턴입니다"));
}

void AMyPlayerController::ServerSubmitGuess_Implementation(const FString& InputNumber)
{
	check(GetWorld());
	AMyGameMode* GM = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());

	check(GM);
	GM->CheckAnswer(this, InputNumber);
}

void AMyPlayerController::ClientReceiveResult_Implementation(const FString& InputNumber, int32 Strike, int32 Ball)
{
	check(HUDWidgetInstance);
	HUDWidgetInstance->ShowJudgementResult(InputNumber, Strike, Ball);
}

void AMyPlayerController::ClientOnGameWin_Implementation()
{
	check(HUDWidgetInstance);
	HUDWidgetInstance->DoWinProcess();
}

void AMyPlayerController::ClientOnGameLose_Implementation()
{
	check(HUDWidgetInstance);
	HUDWidgetInstance->DoLoseProcess();
}

void AMyPlayerController::ServerRequestRestart_Implementation()
{
	AMyGameMode* GM = GetWorld()->GetAuthGameMode<AMyGameMode>();

	check(GM);
	GM->RequestRestartGame(this);
}

void AMyPlayerController::ClientResettingButtons_Implementation()
{
	check(HUDWidgetInstance);
	HUDWidgetInstance->ResetUI();
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController())
	{
		CreateWidgetOnViewport();
		ServerSendReadyValue(true);
	}
}

void AMyPlayerController::ServerSendReadyValue_Implementation(bool IsReady)
{
	check(IsReady);
	AMyGameMode* GM = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
	{
		GM->ReadyCount++;
		UE_LOG(LogTemp, Warning, TEXT("Received value: %d"), GM->ReadyCount);

		if (GM->ReadyCount == 2)
		{
			GM->Ready();
		}
	}
}

void AMyPlayerController::CreateWidgetOnViewport()
{
	check(HUDWidgetClass);
	HUDWidgetInstance = CreateWidget<UWidget_Main>(this, HUDWidgetClass);
	
	check(HUDWidgetInstance);
	HUDWidgetInstance->AddToViewport();
}