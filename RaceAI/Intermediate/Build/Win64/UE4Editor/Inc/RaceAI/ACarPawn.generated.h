// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RACEAI_ACarPawn_generated_h
#error "ACarPawn.generated.h already included, missing '#pragma once' in ACarPawn.h"
#endif
#define RACEAI_ACarPawn_generated_h

#define RaceAI_Source_RaceAI_ACarPawn_h_15_SPARSE_DATA
#define RaceAI_Source_RaceAI_ACarPawn_h_15_RPC_WRAPPERS
#define RaceAI_Source_RaceAI_ACarPawn_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define RaceAI_Source_RaceAI_ACarPawn_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAACarPawn(); \
	friend struct Z_Construct_UClass_AACarPawn_Statics; \
public: \
	DECLARE_CLASS(AACarPawn, ARaceAIPawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RaceAI"), NO_API) \
	DECLARE_SERIALIZER(AACarPawn)


#define RaceAI_Source_RaceAI_ACarPawn_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAACarPawn(); \
	friend struct Z_Construct_UClass_AACarPawn_Statics; \
public: \
	DECLARE_CLASS(AACarPawn, ARaceAIPawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RaceAI"), NO_API) \
	DECLARE_SERIALIZER(AACarPawn)


#define RaceAI_Source_RaceAI_ACarPawn_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AACarPawn(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AACarPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AACarPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AACarPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AACarPawn(AACarPawn&&); \
	NO_API AACarPawn(const AACarPawn&); \
public:


#define RaceAI_Source_RaceAI_ACarPawn_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AACarPawn() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AACarPawn(AACarPawn&&); \
	NO_API AACarPawn(const AACarPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AACarPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AACarPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AACarPawn)


#define RaceAI_Source_RaceAI_ACarPawn_h_15_PRIVATE_PROPERTY_OFFSET
#define RaceAI_Source_RaceAI_ACarPawn_h_12_PROLOG
#define RaceAI_Source_RaceAI_ACarPawn_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RaceAI_Source_RaceAI_ACarPawn_h_15_PRIVATE_PROPERTY_OFFSET \
	RaceAI_Source_RaceAI_ACarPawn_h_15_SPARSE_DATA \
	RaceAI_Source_RaceAI_ACarPawn_h_15_RPC_WRAPPERS \
	RaceAI_Source_RaceAI_ACarPawn_h_15_INCLASS \
	RaceAI_Source_RaceAI_ACarPawn_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define RaceAI_Source_RaceAI_ACarPawn_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RaceAI_Source_RaceAI_ACarPawn_h_15_PRIVATE_PROPERTY_OFFSET \
	RaceAI_Source_RaceAI_ACarPawn_h_15_SPARSE_DATA \
	RaceAI_Source_RaceAI_ACarPawn_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	RaceAI_Source_RaceAI_ACarPawn_h_15_INCLASS_NO_PURE_DECLS \
	RaceAI_Source_RaceAI_ACarPawn_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RACEAI_API UClass* StaticClass<class AACarPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID RaceAI_Source_RaceAI_ACarPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
