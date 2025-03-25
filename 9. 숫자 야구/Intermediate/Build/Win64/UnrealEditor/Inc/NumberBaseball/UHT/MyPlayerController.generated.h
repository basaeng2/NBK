// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NUMBERBASEBALL_MyPlayerController_generated_h
#error "MyPlayerController.generated.h already included, missing '#pragma once' in MyPlayerController.h"
#endif
#define NUMBERBASEBALL_MyPlayerController_generated_h

#define FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientResettingbuttons_Implementation(); \
	virtual void ServerRequestRestart_Implementation(); \
	virtual void ClientOnGameLose_Implementation(); \
	virtual void ClientOnGameWin_Implementation(); \
	virtual void ClientUpdateTurnTime_Implementation(float RemainingTime); \
	virtual void ClientReceiveResult_Implementation(const FString& InputNumber, int32 Strike, int32 Ball); \
	virtual void ServerSubmitGuess_Implementation(const FString& InputNumber); \
	virtual void ClientSetOtherTurn_Implementation(); \
	virtual void ClientSetMyTurn_Implementation(); \
	virtual void ServerSendReadyValue_Implementation(bool IsReady); \
	DECLARE_FUNCTION(execClientResettingbuttons); \
	DECLARE_FUNCTION(execServerRequestRestart); \
	DECLARE_FUNCTION(execClientOnGameLose); \
	DECLARE_FUNCTION(execClientOnGameWin); \
	DECLARE_FUNCTION(execClientUpdateTurnTime); \
	DECLARE_FUNCTION(execClientReceiveResult); \
	DECLARE_FUNCTION(execServerSubmitGuess); \
	DECLARE_FUNCTION(execClientSetOtherTurn); \
	DECLARE_FUNCTION(execClientSetMyTurn); \
	DECLARE_FUNCTION(execServerSendReadyValue);


#define FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_CALLBACK_WRAPPERS
#define FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyPlayerController(); \
	friend struct Z_Construct_UClass_AMyPlayerController_Statics; \
public: \
	DECLARE_CLASS(AMyPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NumberBaseball"), NO_API) \
	DECLARE_SERIALIZER(AMyPlayerController)


#define FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyPlayerController(AMyPlayerController&&); \
	AMyPlayerController(const AMyPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyPlayerController) \
	NO_API virtual ~AMyPlayerController();


#define FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_9_PROLOG
#define FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_CALLBACK_WRAPPERS \
	FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_INCLASS_NO_PURE_DECLS \
	FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NUMBERBASEBALL_API UClass* StaticClass<class AMyPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
