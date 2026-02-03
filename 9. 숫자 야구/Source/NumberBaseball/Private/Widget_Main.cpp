#include "Widget_Main.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "MyPlayerController.h"
#include "MyGameMode.h"
#include "MyGameState.h"

void UNumberKeyWidget::HandleClicked()
{
    if (!MainWidgetPtr) return;

    int32 Length = MainWidgetPtr->GetGuessNumberLength();
    if (Length != 4)
    {
        const FString NumberToString = FString::Printf(TEXT("%d"), ManagingNumber);
        MainWidgetPtr->AppendNumberToGuessText(NumberToString);
        MainWidgetPtr->SetButtonsDisabled(ManagingNumber);
    }
}

void UNumberKeyWidget::SetNumberText(int32 Number)
{
    check(NumberText);
    NumberText->SetText(FText::FromString(FString::Printf(TEXT("%d"), Number)));
}

void UNumberKeyWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (Button)
    {
        Button->OnClicked.AddDynamic(this, &UNumberKeyWidget::HandleClicked);
    }
}

void UWidget_Main::SetButtonsDisabled(const int32 Number)
{
    for (UNumberKeyWidget* NumberButton : NumberKeyWidgets)
    {
        if (NumberButton->ManagingNumber == Number)
        {
            NumberButton->SetIsEnabled(false);
            return;
        }
    }
}

bool UWidget_Main::AppendNumberToGuessText(const FString& NumberStr)
{
    FString CurrentText = GuessNumberText->GetText().ToString();

    if (CurrentText.Len() >= AMyGameMode::GetDigitsCount()) return false;

    CurrentText.Append(NumberStr);
    GuessNumberText->SetText(FText::FromString(CurrentText));

    return true;
}

int32 UWidget_Main::GetGuessNumberLength() const
{
    return GuessNumberText ? GuessNumberText->GetText().ToString().Len() : 0;
}

void UWidget_Main::SetAllButtonsEnabled(const bool bEnable)
{
    for (UWidget* Widget : NumberKeyWidgets)
    {
        Widget->SetIsEnabled(bEnable);
    }

    GuessButton->SetIsEnabled(bEnable);
    ResetButton->SetIsEnabled(bEnable);
    BackspaceButton->SetIsEnabled(bEnable);
}

void UWidget_Main::ClearGuessNumberTextMessage()
{
    check(GuessNumberText);
    GuessNumberText->SetText(FText::GetEmpty());
}

void UWidget_Main::ClearJudgementTextMessage()
{
    check(JudgementText);
    JudgementText->SetText(FText::GetEmpty());
}

void UWidget_Main::ShowSignMessage(const FString& Message)
{
    check(SignText);
    SignText->SetText(FText::FromString(Message));
}

void UWidget_Main::ShowJudgementResult(const FString& InputNumber, const int32 Strike, const int32 Ball)
{
    FString ResultText;

    if (Strike == 0 && Ball == 0)
    {
        ResultText = FString::Printf(TEXT("%s: OUT"), *InputNumber);
    }
    else
    {
        ResultText = FString::Printf(TEXT("%s: %d S, %d B"), *InputNumber, Strike, Ball);
    }

    check(JudgementText);
    JudgementText->SetText(FText::FromString(ResultText));
}

void UWidget_Main::UpdateTurnTime(float RemainingTime)
{
    check(TimerText);
    FString TimeString = FString::Printf(TEXT("%.1f초"), RemainingTime);
    TimerText->SetText(FText::FromString(TimeString));
}

void UWidget_Main::DoWinProcess()
{
    bIsGameOver = true;
    ShowGameWinMessage();
    SetAllButtonsEnabled(false);
    SetRestartButtonVisible(true);
}

void UWidget_Main::DoLoseProcess()
{
    bIsGameOver = true;
    ShowGameLoseMessage();
    SetAllButtonsEnabled(false);
    SetRestartButtonVisible(true);
}

void UWidget_Main::ShowGameWinMessage()
{
    check(SignText);
    SignText->SetText(FText::FromString(TEXT("You Win")));
}

void UWidget_Main::ShowGameLoseMessage()
{
    check(SignText)
        SignText->SetText(FText::FromString(TEXT("You Lose")));
}

void UWidget_Main::SetRestartButtonVisible(bool bVisible)
{
    if (!bVisible)
    {
        RestartButton->SetVisibility(ESlateVisibility::Collapsed);
    }
    else
    {
        RestartButton->SetVisibility(ESlateVisibility::Visible);
        RestartButton->SetIsEnabled(true);
    }
}

void UWidget_Main::ResetUI()
{
    if (GuessNumberText) GuessNumberText->SetText(FText::GetEmpty());
    if (SignText) SignText->SetText(FText::GetEmpty());
    if (JudgementText) JudgementText->SetText(FText::GetEmpty());
    if (TimerText) TimerText->SetText(FText::GetEmpty());

    SetAllButtonsEnabled(true);
    SetRestartButtonVisible(false);

    bIsGameOver = false;
}

void UWidget_Main::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    NumberKeyWidgets = {
        Button_1,
        Button_2,
        Button_3,
        Button_4,
        Button_5,
        Button_6,
        Button_7,
        Button_8,
        Button_9
    };

    for (UNumberKeyWidget* NumberButton : NumberKeyWidgets)
    {
        check(NumberButton);
        NumberButton->MainWidgetPtr = this;

        FString WidgetName = NumberButton->GetName();
        FString LastChar = WidgetName.Right(1);

        int32 Number = FCString::Atoi(*LastChar);

        check(Number >= 1 && Number <= 9);
        NumberButton->ManagingNumber = Number;
        NumberButton->SetNumberText(Number);
    }

    check(BackspaceButton);
    BackspaceButton->OnClicked.AddDynamic(this, &UWidget_Main::OnBackspaceButtonClicked);

    check(ResetButton);
    ResetButton->OnClicked.AddDynamic(this, &UWidget_Main::OnResetButtonClicked);

    check(GuessButton);
    GuessButton->OnClicked.AddDynamic(this, &UWidget_Main::OnGuessButtonClicked);

    check(RestartButton);
    RestartButton->OnClicked.AddDynamic(this, &UWidget_Main::OnRestartButtonClicked);
}

void UWidget_Main::NativeConstruct()
{
    Super::NativeConstruct();

    SetRestartButtonVisible(false);
    SetAllButtonsEnabled(true);
}

void UWidget_Main::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    if (bIsGameOver) return;

    AMyGameState* GS = GetWorld()->GetGameState<AMyGameState>();
    if (GS)
    {
        UpdateTurnTime(GS->GetRemainingTurnTime());
    }
}

void UWidget_Main::OnBackspaceButtonClicked()
{
    if (!GuessNumberText) return;

    FString CurrentText = GuessNumberText->GetText().ToString();

    if (CurrentText.Len() == 0) return;

    TCHAR LastChar = CurrentText[CurrentText.Len() - 1];
    CurrentText.LeftChopInline(1);
    GuessNumberText->SetText(FText::FromString(CurrentText));

    int32 LastNumber = LastChar - '0';
    SetButtonsEnabled(LastNumber);
}

void UWidget_Main::OnResetButtonClicked()
{
    check(GuessNumberText);
    GuessNumberText->SetText(FText::GetEmpty());

    SetAllButtonsEnabled(true);
}

void UWidget_Main::OnGuessButtonClicked()
{
    FString InputText = GuessNumberText->GetText().ToString();

    if (InputText.Len() != AMyGameMode::GetDigitsCount())
    {
        ShowSignMessage(TEXT("4자리 숫자를 입력하세요"));
        GuessNumberText->SetText(FText::GetEmpty());

        SetAllButtonsEnabled(true);
        return;
    }

    AMyPlayerController* PC = Cast<AMyPlayerController>(GetOwningPlayer());

    check(PC);
    PC->ServerSubmitGuess(InputText);

    ClearGuessNumberTextMessage();
}

void UWidget_Main::OnRestartButtonClicked()
{
    AMyPlayerController* PC = Cast<AMyPlayerController>(GetOwningPlayer());

    check(PC);
    PC->ServerRequestRestart();
}

void UWidget_Main::SetButtonsEnabled(const int32 Number)
{
    for (UNumberKeyWidget* NumberButton : NumberKeyWidgets)
    {
        if (NumberButton->ManagingNumber == Number)
        {
            NumberButton->SetIsEnabled(true);
            return;
        }
    }
}