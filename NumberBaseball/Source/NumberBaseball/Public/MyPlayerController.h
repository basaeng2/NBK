#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UWidget_Main;

UCLASS()
class NUMBERBASEBALL_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void CreateWidgetOnViewport();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void ServerSendReadyValue(bool IsReady);

public:
	AMyPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<UUserWidget> HUDWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	UUserWidget* HUDWidgetInstance;

	UFUNCTION(Client, Reliable)
	void ClientSetMyTurn();

	UFUNCTION(Client, Reliable)
	void ClientSetOtherTurn();

	UFUNCTION(Server, Reliable)
	void ServerSubmitGuess(const FString& InputNumber);

	UFUNCTION(Client, Reliable)
	void ClientReceiveResult(const FString& InputNumber, int32 Strike, int32 Ball);

	UFUNCTION(Client, Reliable)
	void ClientUpdateTurnTime(float RemainingTime);

	UFUNCTION(Client, Reliable)
	void ClientOnGameWin();

	UFUNCTION(Client, Reliable)
	void ClientOnGameLose();

	UFUNCTION(Server, Reliable)
	void ServerRequestRestart();

	UFUNCTION(Client, Reliable)
	void ClientResettingbuttons();
};