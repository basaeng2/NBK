// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NumberBaseball/Public/MyGameState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyGameState() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameState();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
NUMBERBASEBALL_API UClass* Z_Construct_UClass_AMyGameState();
NUMBERBASEBALL_API UClass* Z_Construct_UClass_AMyGameState_NoRegister();
UPackage* Z_Construct_UPackage__Script_NumberBaseball();
// End Cross Module References

// Begin Class AMyGameState
void AMyGameState::StaticRegisterNativesAMyGameState()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyGameState);
UClass* Z_Construct_UClass_AMyGameState_NoRegister()
{
	return AMyGameState::StaticClass();
}
struct Z_Construct_UClass_AMyGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MyGameState.h" },
		{ "ModuleRelativePath", "Public/MyGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTurnPlayer_MetaData[] = {
		{ "ModuleRelativePath", "Public/MyGameState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTurnTimeRemaining_MetaData[] = {
		{ "ModuleRelativePath", "Public/MyGameState.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTurnPlayer;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTurnTimeRemaining;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyGameState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyGameState_Statics::NewProp_CurrentTurnPlayer = { "CurrentTurnPlayer", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyGameState, CurrentTurnPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTurnPlayer_MetaData), NewProp_CurrentTurnPlayer_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyGameState_Statics::NewProp_CurrentTurnTimeRemaining = { "CurrentTurnTimeRemaining", nullptr, (EPropertyFlags)0x0040000000000020, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyGameState, CurrentTurnTimeRemaining), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTurnTimeRemaining_MetaData), NewProp_CurrentTurnTimeRemaining_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyGameState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyGameState_Statics::NewProp_CurrentTurnPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyGameState_Statics::NewProp_CurrentTurnTimeRemaining,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameState_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyGameState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameState,
	(UObject* (*)())Z_Construct_UPackage__Script_NumberBaseball,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyGameState_Statics::ClassParams = {
	&AMyGameState::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMyGameState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameState_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyGameState_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyGameState_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyGameState()
{
	if (!Z_Registration_Info_UClass_AMyGameState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyGameState.OuterSingleton, Z_Construct_UClass_AMyGameState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyGameState.OuterSingleton;
}
template<> NUMBERBASEBALL_API UClass* StaticClass<AMyGameState>()
{
	return AMyGameState::StaticClass();
}
void AMyGameState::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_CurrentTurnPlayer(TEXT("CurrentTurnPlayer"));
	static const FName Name_CurrentTurnTimeRemaining(TEXT("CurrentTurnTimeRemaining"));
	const bool bIsValid = true
		&& Name_CurrentTurnPlayer == ClassReps[(int32)ENetFields_Private::CurrentTurnPlayer].Property->GetFName()
		&& Name_CurrentTurnTimeRemaining == ClassReps[(int32)ENetFields_Private::CurrentTurnTimeRemaining].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AMyGameState"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyGameState);
AMyGameState::~AMyGameState() {}
// End Class AMyGameState

// Begin Registration
struct Z_CompiledInDeferFile_FID_NumberBaseball_Source_NumberBaseball_Public_MyGameState_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyGameState, AMyGameState::StaticClass, TEXT("AMyGameState"), &Z_Registration_Info_UClass_AMyGameState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyGameState), 1701517433U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NumberBaseball_Source_NumberBaseball_Public_MyGameState_h_2052123857(TEXT("/Script/NumberBaseball"),
	Z_CompiledInDeferFile_FID_NumberBaseball_Source_NumberBaseball_Public_MyGameState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NumberBaseball_Source_NumberBaseball_Public_MyGameState_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
