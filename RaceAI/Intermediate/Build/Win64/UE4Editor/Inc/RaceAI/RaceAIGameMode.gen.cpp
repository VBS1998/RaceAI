// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaceAI/RaceAIGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaceAIGameMode() {}
// Cross Module References
	RACEAI_API UClass* Z_Construct_UClass_ARaceAIGameMode_NoRegister();
	RACEAI_API UClass* Z_Construct_UClass_ARaceAIGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_RaceAI();
// End Cross Module References
	void ARaceAIGameMode::StaticRegisterNativesARaceAIGameMode()
	{
	}
	UClass* Z_Construct_UClass_ARaceAIGameMode_NoRegister()
	{
		return ARaceAIGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ARaceAIGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARaceAIGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_RaceAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARaceAIGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "RaceAIGameMode.h" },
		{ "ModuleRelativePath", "RaceAIGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARaceAIGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARaceAIGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARaceAIGameMode_Statics::ClassParams = {
		&ARaceAIGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ARaceAIGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARaceAIGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARaceAIGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARaceAIGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARaceAIGameMode, 208024433);
	template<> RACEAI_API UClass* StaticClass<ARaceAIGameMode>()
	{
		return ARaceAIGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARaceAIGameMode(Z_Construct_UClass_ARaceAIGameMode, &ARaceAIGameMode::StaticClass, TEXT("/Script/RaceAI"), TEXT("ARaceAIGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARaceAIGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
