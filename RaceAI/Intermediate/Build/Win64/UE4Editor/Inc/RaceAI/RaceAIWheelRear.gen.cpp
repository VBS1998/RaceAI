// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RaceAI/RaceAIWheelRear.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaceAIWheelRear() {}
// Cross Module References
	RACEAI_API UClass* Z_Construct_UClass_URaceAIWheelRear_NoRegister();
	RACEAI_API UClass* Z_Construct_UClass_URaceAIWheelRear();
	PHYSXVEHICLES_API UClass* Z_Construct_UClass_UVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_RaceAI();
// End Cross Module References
	void URaceAIWheelRear::StaticRegisterNativesURaceAIWheelRear()
	{
	}
	UClass* Z_Construct_UClass_URaceAIWheelRear_NoRegister()
	{
		return URaceAIWheelRear::StaticClass();
	}
	struct Z_Construct_UClass_URaceAIWheelRear_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URaceAIWheelRear_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_RaceAI,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaceAIWheelRear_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RaceAIWheelRear.h" },
		{ "ModuleRelativePath", "RaceAIWheelRear.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URaceAIWheelRear_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URaceAIWheelRear>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_URaceAIWheelRear_Statics::ClassParams = {
		&URaceAIWheelRear::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_URaceAIWheelRear_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URaceAIWheelRear_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URaceAIWheelRear()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_URaceAIWheelRear_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URaceAIWheelRear, 1889144304);
	template<> RACEAI_API UClass* StaticClass<URaceAIWheelRear>()
	{
		return URaceAIWheelRear::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_URaceAIWheelRear(Z_Construct_UClass_URaceAIWheelRear, &URaceAIWheelRear::StaticClass, TEXT("/Script/RaceAI"), TEXT("URaceAIWheelRear"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URaceAIWheelRear);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
