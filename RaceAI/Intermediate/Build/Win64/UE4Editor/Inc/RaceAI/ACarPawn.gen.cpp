// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaceAI/ACarPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeACarPawn() {}
// Cross Module References
	RACEAI_API UClass* Z_Construct_UClass_AACarPawn_NoRegister();
	RACEAI_API UClass* Z_Construct_UClass_AACarPawn();
	RACEAI_API UClass* Z_Construct_UClass_ARaceAIPawn();
	UPackage* Z_Construct_UPackage__Script_RaceAI();
// End Cross Module References
	void AACarPawn::StaticRegisterNativesAACarPawn()
	{
	}
	UClass* Z_Construct_UClass_AACarPawn_NoRegister()
	{
		return AACarPawn::StaticClass();
	}
	struct Z_Construct_UClass_AACarPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AACarPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ARaceAIPawn,
		(UObject* (*)())Z_Construct_UPackage__Script_RaceAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AACarPawn_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ACarPawn.h" },
		{ "ModuleRelativePath", "ACarPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AACarPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AACarPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AACarPawn_Statics::ClassParams = {
		&AACarPawn::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AACarPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AACarPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AACarPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AACarPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AACarPawn, 1542686993);
	template<> RACEAI_API UClass* StaticClass<AACarPawn>()
	{
		return AACarPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AACarPawn(Z_Construct_UClass_AACarPawn, &AACarPawn::StaticClass, TEXT("/Script/RaceAI"), TEXT("AACarPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AACarPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
