// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Widget_Main.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NUMBERBASEBALL_Widget_Main_generated_h
#error "Widget_Main.generated.h already included, missing '#pragma once' in Widget_Main.h"
#endif
#define NUMBERBASEBALL_Widget_Main_generated_h

#define FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRestartButtonClicked); \
	DECLARE_FUNCTION(execOnGuessButtonClicked); \
	DECLARE_FUNCTION(execOnResetButtonClicked); \
	DECLARE_FUNCTION(execOnBackspceButtonClicked); \
	DECLARE_FUNCTION(execOnNumberButtonClicked9); \
	DECLARE_FUNCTION(execOnNumberButtonClicked8); \
	DECLARE_FUNCTION(execOnNumberButtonClicked7); \
	DECLARE_FUNCTION(execOnNumberButtonClicked6); \
	DECLARE_FUNCTION(execOnNumberButtonClicked5); \
	DECLARE_FUNCTION(execOnNumberButtonClicked4); \
	DECLARE_FUNCTION(execOnNumberButtonClicked3); \
	DECLARE_FUNCTION(execOnNumberButtonClicked2); \
	DECLARE_FUNCTION(execOnNumberButtonClicked1);


#define FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWidget_Main(); \
	friend struct Z_Construct_UClass_UWidget_Main_Statics; \
public: \
	DECLARE_CLASS(UWidget_Main, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NumberBaseball"), NO_API) \
	DECLARE_SERIALIZER(UWidget_Main)


#define FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWidget_Main(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UWidget_Main(UWidget_Main&&); \
	UWidget_Main(const UWidget_Main&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWidget_Main); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWidget_Main); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWidget_Main) \
	NO_API virtual ~UWidget_Main();


#define FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h_9_PROLOG
#define FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h_12_INCLASS_NO_PURE_DECLS \
	FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NUMBERBASEBALL_API UClass* StaticClass<class UWidget_Main>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_NumberBaseball_Source_NumberBaseball_Public_Widget_Main_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
