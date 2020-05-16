// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaceAI/RaceAIWheelFront.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaceAIWheelFront() {}
// Cross Module References
	RACEAI_API UClass* Z_Construct_UClass_URaceAIWheelFront_NoRegister();
	RACEAI_API UClass* Z_Construct_UClass_URaceAIWheelFront();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_UVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_RaceAI();
// End Cross Module References
	void URaceAIWheelFront::StaticRegisterNativesURaceAIWheelFront()
	{
	}
	UClass* Z_Construct_UClass_URaceAIWheelFront_NoRegister()
	{
		return URaceAIWheelFront::StaticClass();
	}
	struct Z_Construct_UClass_URaceAIWheelFront_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URaceAIWheelFront_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_RaceAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaceAIWheelFront_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RaceAIWheelFront.h" },
		{ "ModuleRelativePath", "RaceAIWheelFront.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URaceAIWheelFront_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URaceAIWheelFront>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URaceAIWheelFront_Statics::ClassParams = {
		&URaceAIWheelFront::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_URaceAIWheelFront_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URaceAIWheelFront_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URaceAIWheelFront()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URaceAIWheelFront_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URaceAIWheelFront, 1724148601);
	template<> RACEAI_API UClass* StaticClass<URaceAIWheelFront>()
	{
		return URaceAIWheelFront::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URaceAIWheelFront(Z_Construct_UClass_URaceAIWheelFront, &URaceAIWheelFront::StaticClass, TEXT("/Script/RaceAI"), TEXT("URaceAIWheelFront"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URaceAIWheelFront);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
