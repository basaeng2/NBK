#include "Widget_Main.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "MyPlayerController.h"
#include "MyGameMode.h"

void UWidget_Main::NativeConstruct()
{
    Super::NativeConstruct();

    SetRestartButtonVisible(false);
    SetAllButtonsEnabled(true);

    if (Button_1) Button_1->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked1);
    if (Button_2) Button_2->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked2);
    if (Button_3) Button_3->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked3);
    if (Button_4) Button_4->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked4);
    if (Button_5) Button_5->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked5);
    if (Button_6) Button_6->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked6);
    if (Button_7) Button_7->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked7);
    if (Button_8) Button_8->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked8);
    if (Button_9) Button_9->OnClicked.AddDynamic(this, &UWidget_Main::OnNumberButtonClicked9);
    if (BackspaceButton) BackspaceButton->OnClicked.AddDynamic(this, &UWidget_Main::OnBackspceButtonClicked);
    if (ResetButton) ResetButton->OnClicked.AddDynamic(this, &UWidget_Main::OnResetButtonClicked);
    if (GuessButton) GuessButton->OnClicked.AddDynamic(this, &UWidget_Main::OnGuessButtonClicked);
    if (RestartButton) RestartButton->OnClicked.AddDynamic(this, &UWidget_Main::OnRestartButtonClicked);
}

void UWidget_Main::OnNumberButtonClicked1() { if (AppendNumberToGuessText(TEXT("1"))) { SetButton('1'); } };    
void UWidget_Main::OnNumberButtonClicked2() { if (AppendNumberToGuessText(TEXT("2"))) { SetButtonsDisenabled('2'); } };
void UWidget_Main::OnNumberButtonClicked3() { if (AppendNumberToGuessText(TEXT("3"))) { SetButtonsDisenabled('3'); } };
void UWidget_Main::OnNumberButtonClicked4() { if (AppendNumberToGuessText(TEXT("4"))) { SetButtonsDisenabled('4'); } };
void UWidget_Main::OnNumberButtonClicked5() { if (AppendNumberToGuessText(TEXT("5"))) { SetButtonsDisenabled('5'); } };
void UWidget_Main::OnNumberButtonClicked6() { if (AppendNumberToGuessText(TEXT("6"))) { SetButtonsDisenabled('6'); } };
void UWidget_Main::OnNumberButtonClicked7() { if (AppendNumberToGuessText(TEXT("7"))) { SetButtonsDisenabled('7'); } };
void UWidget_Main::OnNumberButtonClicked8() { if (AppendNumberToGuessText(TEXT("8"))) { SetButtonsDisenabled('8'); } };
void UWidget_Main::OnNumberButtonClicked9() { if (AppendNumberToGuessText(TEXT("9"))) { SetButtonsDisenabled('9'); } };

bool UWidget_Main::AppendNumberToGuessText(const FString& NumberStr)
{
    FString CurrentText = GuessNumberText->GetText().ToString();

    if (CurrentText.Len() >= AMyGameMode::GetDigitsCount()) return false;

    CurrentText.Append(NumberStr);
    GuessNumberText->SetText(FText::FromString(CurrentText));

    return true;
}

void UWidget_Main::SetButtonsEnabled(TCHAR NumberChar)
{
    switch (NumberChar)
    {
    case '1': if (Button_1) Button_1->SetIsEnabled(true); break;
    case '2': if (Button_2) Button_2->SetIsEnabled(true); break;
    case '3': if (Button_3) Button_3->SetIsEnabled(true); break;
    case '4': if (Button_4) Button_4->SetIsEnabled(true); break;
    case '5': if (Button_5) Button_5->SetIsEnabled(true); break;
    case '6': if (Button_6) Button_6->SetIsEnabled(true); break;
    case '7': if (Button_7) Button_7->SetIsEnabled(true); break;
    case '8': if (Button_8) Button_8->SetIsEnabled(true); break;
    case '9': if (Button_9) Button_9->SetIsEnabled(true); break;
    }
}

void UWidget_Main::SetButtonsDisenabled(TCHAR NumberChar)
{
    switch (NumberChar)
    {
    case '1': if (Button_1) Button_1->SetIsEnabled(false); break;
    case '2': if (Button_2) Button_2->SetIsEnabled(false); break;
    case '3': if (Button_3) Button_3->SetIsEnabled(false); break;
    case '4': if (Button_4) Button_4->SetIsEnabled(false); break;
    case '5': if (Button_5) Button_5->SetIsEnabled(false); break;
    case '6': if (Button_6) Button_6->SetIsEnabled(false); break;
    case '7': if (Button_7) Button_7->SetIsEnabled(false); break;
    case '8': if (Button_8) Button_8->SetIsEnabled(false); break;
    case '9': if (Button_9) Button_9->SetIsEnabled(false); break;
    }
}

void UWidget_Main::OnBackspceButtonClicked()
{
    if (!GuessNumberText) return;

    FString CurrentText = GuessNumberText->GetText().ToString();
    if (CurrentText.Len() > 0)
    {
        TCHAR LastChar = CurrentText[CurrentText.Len() - 1];

        CurrentText.LeftChopInline(1);
        GuessNumberText->SetText(FText::FromString(CurrentText));

        SetButtonsEnabled(LastChar);
    }
}

void UWidget_Main::OnResetButtonClicked()
{
    if (GuessNumberText)
    {
        GuessNumberText->SetText(FText::FromString(TEXT("")));
    }

    SetAllButtonsEnabled(true);
}

void UWidget_Main::OnGuessButtonClicked()
{
    FString InputText = GuessNumberText->GetText().ToString();

    if (InputText.Len() != AMyGameMode::GetDigitsCount())
    {
        ShowSIgnMessage(TEXT("4자리 숫자를 입력하세요"));
        GuessNumberText->SetText(FText::FromString(TEXT("")));

        SetAllButtonsEnabled(true);
        return;
    }

    AMyPlayerController* PC = Cast<AMyPlayerController>(GetOwningPlayer());
    if (PC)
    {
        PC->ServerSubmitGuess(InputText);
    }

    ClearGuessNumberTextMessage();
}

void UWidget_Main::OnRestartButtonClicked()
{
    AMyPlayerController* PC = Cast<AMyPlayerController>(GetOwningPlayer());
    if (PC)
    {
        PC->ServerRequestRestart();
    }
}

void UWidget_Main::SetAllButtonsEnabled(bool bEnable)
{
    if (WidgetTree)
    {
        TArray<UWidget*> AllWidgets;
        WidgetTree->GetAllWidgets(AllWidgets);

        for (UWidget* Widget : AllWidgets)
        {
            if (UButton* Button = Cast<UButton>(Widget))
            {
                Button->SetIsEnabled(bEnable);
            }
        }
    }
}

void UWidget_Main::ClearGuessNumberTextMessage()
{
    if (GuessNumberText)
    {
        GuessNumberText->SetText(FText::FromString(TEXT("")));
    }
}

void UWidget_Main::ClearJudgementTextMessage()
{
    if (JudgementText)
    {
        JudgementText->SetText(FText::FromString(TEXT("")));
    }
}

void UWidget_Main::ShowSIgnMessage(const FString& Message)
{
    if (SignText)
    {
        SignText->SetText(FText::FromString(Message));
    }
}

void UWidget_Main::ShowJudgementResult(const FString& InputNumber, int32 Strike, int32 Ball)
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

    if (JudgementText)
    {
        JudgementText->SetText(FText::FromString(ResultText));
    }
}

void UWidget_Main::UpdateTurnTimeDisplay(float RemainingTime)
{
    if (TimerText)
    {
        FString TimeString = FString::Printf(TEXT("%.1f초"), RemainingTime);

        TimerText->SetText(FText::FromString(TimeString));
    }
}

void UWidget_Main::ShowGameWinMessage()
{
    if (SignText)
    {
        SignText->SetText(FText::FromString(TEXT("You Win")));
    }
}

void UWidget_Main::ShowGameLoseMessage()
{
    if (SignText)
    {
        SignText->SetText(FText::FromString(TEXT("You Lose")));
    }
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
    if (GuessNumberText) GuessNumberText->SetText(FText::FromString(TEXT("")));
    if (SignText) SignText->SetText(FText::FromString(TEXT("")));
    if (JudgementText) JudgementText->SetText(FText::FromString(TEXT("")));
    if (TimerText) TimerText->SetText(FText::FromString(TEXT("")));

    SetAllButtonsEnabled(true);
    SetRestartButtonVisible(false);
}
