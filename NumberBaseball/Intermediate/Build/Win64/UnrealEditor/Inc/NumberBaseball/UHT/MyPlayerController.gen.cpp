// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NumberBaseball/Public/MyPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyPlayerController() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
NUMBERBASEBALL_API UClass* Z_Construct_UClass_AMyPlayerController();
NUMBERBASEBALL_API UClass* Z_Construct_UClass_AMyPlayerController_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_NumberBaseball();
// End Cross Module References

// Begin Class AMyPlayerController Function ClientOnGameLose
static const FName NAME_AMyPlayerController_ClientOnGameLose = FName(TEXT("ClientOnGameLose"));
void AMyPlayerController::ClientOnGameLose()
{
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ClientOnGameLose);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMyPlayerController_ClientOnGameLose_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ClientOnGameLose_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ClientOnGameLose", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientOnGameLose_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ClientOnGameLose_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyPlayerController_ClientOnGameLose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ClientOnGameLose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execClientOnGameLose)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnGameLose_Implementation();
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ClientOnGameLose

// Begin Class AMyPlayerController Function ClientOnGameWin
static const FName NAME_AMyPlayerController_ClientOnGameWin = FName(TEXT("ClientOnGameWin"));
void AMyPlayerController::ClientOnGameWin()
{
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ClientOnGameWin);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMyPlayerController_ClientOnGameWin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ClientOnGameWin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ClientOnGameWin", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientOnGameWin_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ClientOnGameWin_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyPlayerController_ClientOnGameWin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ClientOnGameWin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execClientOnGameWin)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnGameWin_Implementation();
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ClientOnGameWin

// Begin Class AMyPlayerController Function ClientReceiveResult
struct MyPlayerController_eventClientReceiveResult_Parms
{
	FString InputNumber;
	int32 Strike;
	int32 Ball;
};
static const FName NAME_AMyPlayerController_ClientReceiveResult = FName(TEXT("ClientReceiveResult"));
void AMyPlayerController::ClientReceiveResult(const FString& InputNumber, int32 Strike, int32 Ball)
{
	MyPlayerController_eventClientReceiveResult_Parms Parms;
	Parms.InputNumber=InputNumber;
	Parms.Strike=Strike;
	Parms.Ball=Ball;
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ClientReceiveResult);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InputNumber;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Strike;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Ball;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::NewProp_InputNumber = { "InputNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayerController_eventClientReceiveResult_Parms, InputNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputNumber_MetaData), NewProp_InputNumber_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::NewProp_Strike = { "Strike", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayerController_eventClientReceiveResult_Parms, Strike), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::NewProp_Ball = { "Ball", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayerController_eventClientReceiveResult_Parms, Ball), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::NewProp_InputNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::NewProp_Strike,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::NewProp_Ball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ClientReceiveResult", nullptr, nullptr, Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::PropPointers), sizeof(MyPlayerController_eventClientReceiveResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::Function_MetaDataParams) };
static_assert(sizeof(MyPlayerController_eventClientReceiveResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execClientReceiveResult)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InputNumber);
	P_GET_PROPERTY(FIntProperty,Z_Param_Strike);
	P_GET_PROPERTY(FIntProperty,Z_Param_Ball);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientReceiveResult_Implementation(Z_Param_InputNumber,Z_Param_Strike,Z_Param_Ball);
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ClientReceiveResult

// Begin Class AMyPlayerController Function ClientResettingbuttons
static const FName NAME_AMyPlayerController_ClientResettingbuttons = FName(TEXT("ClientResettingbuttons"));
void AMyPlayerController::ClientResettingbuttons()
{
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ClientResettingbuttons);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMyPlayerController_ClientResettingbuttons_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ClientResettingbuttons_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ClientResettingbuttons", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientResettingbuttons_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ClientResettingbuttons_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyPlayerController_ClientResettingbuttons()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ClientResettingbuttons_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execClientResettingbuttons)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientResettingbuttons_Implementation();
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ClientResettingbuttons

// Begin Class AMyPlayerController Function ClientSetMyTurn
static const FName NAME_AMyPlayerController_ClientSetMyTurn = FName(TEXT("ClientSetMyTurn"));
void AMyPlayerController::ClientSetMyTurn()
{
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ClientSetMyTurn);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMyPlayerController_ClientSetMyTurn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ClientSetMyTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ClientSetMyTurn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientSetMyTurn_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ClientSetMyTurn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyPlayerController_ClientSetMyTurn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ClientSetMyTurn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execClientSetMyTurn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientSetMyTurn_Implementation();
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ClientSetMyTurn

// Begin Class AMyPlayerController Function ClientSetOtherTurn
static const FName NAME_AMyPlayerController_ClientSetOtherTurn = FName(TEXT("ClientSetOtherTurn"));
void AMyPlayerController::ClientSetOtherTurn()
{
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ClientSetOtherTurn);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMyPlayerController_ClientSetOtherTurn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ClientSetOtherTurn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ClientSetOtherTurn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientSetOtherTurn_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ClientSetOtherTurn_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyPlayerController_ClientSetOtherTurn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ClientSetOtherTurn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execClientSetOtherTurn)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientSetOtherTurn_Implementation();
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ClientSetOtherTurn

// Begin Class AMyPlayerController Function ClientUpdateTurnTime
struct MyPlayerController_eventClientUpdateTurnTime_Parms
{
	float RemainingTime;
};
static const FName NAME_AMyPlayerController_ClientUpdateTurnTime = FName(TEXT("ClientUpdateTurnTime"));
void AMyPlayerController::ClientUpdateTurnTime(float RemainingTime)
{
	MyPlayerController_eventClientUpdateTurnTime_Parms Parms;
	Parms.RemainingTime=RemainingTime;
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ClientUpdateTurnTime);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RemainingTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::NewProp_RemainingTime = { "RemainingTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayerController_eventClientUpdateTurnTime_Parms, RemainingTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::NewProp_RemainingTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ClientUpdateTurnTime", nullptr, nullptr, Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::PropPointers), sizeof(MyPlayerController_eventClientUpdateTurnTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::Function_MetaDataParams) };
static_assert(sizeof(MyPlayerController_eventClientUpdateTurnTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execClientUpdateTurnTime)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_RemainingTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientUpdateTurnTime_Implementation(Z_Param_RemainingTime);
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ClientUpdateTurnTime

// Begin Class AMyPlayerController Function ServerRequestRestart
static const FName NAME_AMyPlayerController_ServerRequestRestart = FName(TEXT("ServerRequestRestart"));
void AMyPlayerController::ServerRequestRestart()
{
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ServerRequestRestart);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AMyPlayerController_ServerRequestRestart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ServerRequestRestart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ServerRequestRestart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ServerRequestRestart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ServerRequestRestart_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyPlayerController_ServerRequestRestart()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ServerRequestRestart_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execServerRequestRestart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRequestRestart_Implementation();
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ServerRequestRestart

// Begin Class AMyPlayerController Function ServerSendReadyValue
struct MyPlayerController_eventServerSendReadyValue_Parms
{
	bool IsReady;
};
static const FName NAME_AMyPlayerController_ServerSendReadyValue = FName(TEXT("ServerSendReadyValue"));
void AMyPlayerController::ServerSendReadyValue(bool IsReady)
{
	MyPlayerController_eventServerSendReadyValue_Parms Parms;
	Parms.IsReady=IsReady ? true : false;
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ServerSendReadyValue);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static void NewProp_IsReady_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsReady;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::NewProp_IsReady_SetBit(void* Obj)
{
	((MyPlayerController_eventServerSendReadyValue_Parms*)Obj)->IsReady = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::NewProp_IsReady = { "IsReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyPlayerController_eventServerSendReadyValue_Parms), &Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::NewProp_IsReady_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::NewProp_IsReady,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ServerSendReadyValue", nullptr, nullptr, Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::PropPointers), sizeof(MyPlayerController_eventServerSendReadyValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00280CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::Function_MetaDataParams) };
static_assert(sizeof(MyPlayerController_eventServerSendReadyValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execServerSendReadyValue)
{
	P_GET_UBOOL(Z_Param_IsReady);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSendReadyValue_Implementation(Z_Param_IsReady);
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ServerSendReadyValue

// Begin Class AMyPlayerController Function ServerSubmitGuess
struct MyPlayerController_eventServerSubmitGuess_Parms
{
	FString InputNumber;
};
static const FName NAME_AMyPlayerController_ServerSubmitGuess = FName(TEXT("ServerSubmitGuess"));
void AMyPlayerController::ServerSubmitGuess(const FString& InputNumber)
{
	MyPlayerController_eventServerSubmitGuess_Parms Parms;
	Parms.InputNumber=InputNumber;
	UFunction* Func = FindFunctionChecked(NAME_AMyPlayerController_ServerSubmitGuess);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputNumber_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_InputNumber;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::NewProp_InputNumber = { "InputNumber", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayerController_eventServerSubmitGuess_Parms, InputNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputNumber_MetaData), NewProp_InputNumber_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::NewProp_InputNumber,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayerController, nullptr, "ServerSubmitGuess", nullptr, nullptr, Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::PropPointers), sizeof(MyPlayerController_eventServerSubmitGuess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::Function_MetaDataParams) };
static_assert(sizeof(MyPlayerController_eventServerSubmitGuess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayerController::execServerSubmitGuess)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InputNumber);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerSubmitGuess_Implementation(Z_Param_InputNumber);
	P_NATIVE_END;
}
// End Class AMyPlayerController Function ServerSubmitGuess

// Begin Class AMyPlayerController
void AMyPlayerController::StaticRegisterNativesAMyPlayerController()
{
	UClass* Class = AMyPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnGameLose", &AMyPlayerController::execClientOnGameLose },
		{ "ClientOnGameWin", &AMyPlayerController::execClientOnGameWin },
		{ "ClientReceiveResult", &AMyPlayerController::execClientReceiveResult },
		{ "ClientResettingbuttons", &AMyPlayerController::execClientResettingbuttons },
		{ "ClientSetMyTurn", &AMyPlayerController::execClientSetMyTurn },
		{ "ClientSetOtherTurn", &AMyPlayerController::execClientSetOtherTurn },
		{ "ClientUpdateTurnTime", &AMyPlayerController::execClientUpdateTurnTime },
		{ "ServerRequestRestart", &AMyPlayerController::execServerRequestRestart },
		{ "ServerSendReadyValue", &AMyPlayerController::execServerSendReadyValue },
		{ "ServerSubmitGuess", &AMyPlayerController::execServerSubmitGuess },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyPlayerController);
UClass* Z_Construct_UClass_AMyPlayerController_NoRegister()
{
	return AMyPlayerController::StaticClass();
}
struct Z_Construct_UClass_AMyPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "MyPlayerController.h" },
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetInstance_MetaData[] = {
		{ "Category", "HUD" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_HUDWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HUDWidgetInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyPlayerController_ClientOnGameLose, "ClientOnGameLose" }, // 580967685
		{ &Z_Construct_UFunction_AMyPlayerController_ClientOnGameWin, "ClientOnGameWin" }, // 4011567762
		{ &Z_Construct_UFunction_AMyPlayerController_ClientReceiveResult, "ClientReceiveResult" }, // 3909061150
		{ &Z_Construct_UFunction_AMyPlayerController_ClientResettingbuttons, "ClientResettingbuttons" }, // 3778990046
		{ &Z_Construct_UFunction_AMyPlayerController_ClientSetMyTurn, "ClientSetMyTurn" }, // 1781116464
		{ &Z_Construct_UFunction_AMyPlayerController_ClientSetOtherTurn, "ClientSetOtherTurn" }, // 3733316638
		{ &Z_Construct_UFunction_AMyPlayerController_ClientUpdateTurnTime, "ClientUpdateTurnTime" }, // 914425835
		{ &Z_Construct_UFunction_AMyPlayerController_ServerRequestRestart, "ServerRequestRestart" }, // 3431709051
		{ &Z_Construct_UFunction_AMyPlayerController_ServerSendReadyValue, "ServerSendReadyValue" }, // 687184108
		{ &Z_Construct_UFunction_AMyPlayerController_ServerSubmitGuess, "ServerSubmitGuess" }, // 988737328
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMyPlayerController_Statics::NewProp_HUDWidgetClass = { "HUDWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayerController, HUDWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetClass_MetaData), NewProp_HUDWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayerController_Statics::NewProp_HUDWidgetInstance = { "HUDWidgetInstance", nullptr, (EPropertyFlags)0x00100000000a000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayerController, HUDWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetInstance_MetaData), NewProp_HUDWidgetInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayerController_Statics::NewProp_HUDWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayerController_Statics::NewProp_HUDWidgetInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_NumberBaseball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyPlayerController_Statics::ClassParams = {
	&AMyPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMyPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyPlayerController()
{
	if (!Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton, Z_Construct_UClass_AMyPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyPlayerController.OuterSingleton;
}
template<> NUMBERBASEBALL_API UClass* StaticClass<AMyPlayerController>()
{
	return AMyPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyPlayerController);
AMyPlayerController::~AMyPlayerController() {}
// End Class AMyPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyPlayerController, AMyPlayerController::StaticClass, TEXT("AMyPlayerController"), &Z_Registration_Info_UClass_AMyPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyPlayerController), 1141184982U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_616301754(TEXT("/Script/NumberBaseball"),
	Z_CompiledInDeferFile_FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NumberBaseball_Source_NumberBaseball_Public_MyPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
