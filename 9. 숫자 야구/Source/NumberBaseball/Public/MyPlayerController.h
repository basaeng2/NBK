#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UWidget_Main;

UCLASS()
class NUMBERBASEBALL_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<UUserWidget> HUDWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	UWidget_Main* HUDWidgetInstance;

	UFUNCTION()
	void SetMyTurn();

	UFUNCTION()
	void SetOtherTurn();

	UFUNCTION(Server, Reliable)
	void ServerSubmitGuess(const FString& InputNumber);

	UFUNCTION(Client, Reliable)
	void ClientReceiveResult(const FString& InputNumber, int32 Strike, int32 Ball);

	UFUNCTION(Client, Reliable)
	void ClientOnGameWin();

	UFUNCTION(Client, Reliable)
	void ClientOnGameLose();

	UFUNCTION(Server, Reliable)
	void ServerRequestRestart();

	UFUNCTION(Client, Reliable)
	void ClientResettingButtons();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void ServerSendReadyValue(bool IsReady);

private:
	void CreateWidgetOnViewport();
};