#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "Widget_Main.generated.h"

UCLASS()

class UNumberKeyWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY()
    int32 ManagingNumber = INDEX_NONE;

    UPROPERTY()
    UWidget_Main* MainWidgetPtr;

    UFUNCTION()
    void HandleClicked();

    void SetNumberText(int32 Number);

protected:
    virtual void NativeOnInitialized() override;

private:
    UPROPERTY(meta = (BindWidget))
    UButton* Button;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* NumberText;
};

UCLASS()
class NUMBERBASEBALL_API UWidget_Main : public UUserWidget
{
    GENERATED_BODY()

public:
    bool AppendNumberToGuessText(const FString& NumberStr);

    int32 GetGuessNumberLength() const;

    void SetAllButtonsEnabled(const bool bEnable);

    void ClearGuessNumberTextMessage();
    void ClearJudgementTextMessage();

    void ShowSignMessage(const FString& Message);
    void ShowJudgementResult(const FString& InputNumber, const int32 Strike, const int32 Ball);

    void UpdateTurnTime(float RemainingTime);

    UFUNCTION()
    void DoWinProcess();

    UFUNCTION()
    void DoLoseProcess();

    void SetButtonsDisabled(const int32 Number);

    void ShowGameWinMessage();
    void ShowGameLoseMessage();

    void SetRestartButtonVisible(bool bVisible);

    void ResetUI();

protected:
    virtual void NativeOnInitialized() override;
    virtual void NativeConstruct() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_1;

    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_2;

    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_3;

    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_4;

    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_5;

    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_6;

    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_7;

    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_8;

    UPROPERTY(meta = (BindWidget))
    UNumberKeyWidget* Button_9;

    UPROPERTY(meta = (BindWidget))
    TArray<TObjectPtr<UNumberKeyWidget>> NumberKeyWidgets;

    UPROPERTY(meta = (BindWidget))
    UButton* GuessButton;
    UPROPERTY(meta = (BindWidget))
    UButton* ResetButton;
    UPROPERTY(meta = (BindWidget))
    UButton* BackspaceButton;
    UPROPERTY(meta = (BindWidget)) 
    UButton* RestartButton;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* GuessNumberText;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* SignText;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* JudgementText;
    UPROPERTY(meta = (BindWidget))
    UTextBlock* TimerText;

    UFUNCTION()
    void OnBackspaceButtonClicked();

    UFUNCTION()
    void OnResetButtonClicked();

    UFUNCTION()
    void OnGuessButtonClicked();

    UFUNCTION()
    void OnRestartButtonClicked();

    void SetButtonsEnabled(const int32 Number);

    bool bIsGameOver = false;
};