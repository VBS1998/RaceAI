// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaceAI/ACarAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeACarAIController() {}
// Cross Module References
	RACEAI_API UClass* Z_Construct_UClass_AACarAIController_NoRegister();
	RACEAI_API UClass* Z_Construct_UClass_AACarAIController();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_RaceAI();
// End Cross Module References
	void AACarAIController::StaticRegisterNativesAACarAIController()
	{
	}
	UClass* Z_Construct_UClass_AACarAIController_NoRegister()
	{
		return AACarAIController::StaticClass();
	}
	struct Z_Construct_UClass_AACarAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AACarAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_RaceAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AACarAIController_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ACarAIController.h" },
		{ "ModuleRelativePath", "ACarAIController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AACarAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AACarAIController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AACarAIController_Statics::ClassParams = {
		&AACarAIController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AACarAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AACarAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AACarAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AACarAIController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AACarAIController, 1498209100);
	template<> RACEAI_API UClass* StaticClass<AACarAIController>()
	{
		return AACarAIController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AACarAIController(Z_Construct_UClass_AACarAIController, &AACarAIController::StaticClass, TEXT("/Script/RaceAI"), TEXT("AACarAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AACarAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
