// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RACEAI_RaceAIPawn_generated_h
#error "RaceAIPawn.generated.h already included, missing '#pragma once' in RaceAIPawn.h"
#endif
#define RACEAI_RaceAIPawn_generated_h

#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_SPARSE_DATA
#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_RPC_WRAPPERS
#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_RPC_WRAPPERS_NO_PURE_DECLS
#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARaceAIPawn(); \
	friend struct Z_Construct_UClass_ARaceAIPawn_Statics; \
public: \
	DECLARE_CLASS(ARaceAIPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RaceAI"), NO_API) \
	DECLARE_SERIALIZER(ARaceAIPawn)


#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_INCLASS \
private: \
	static void StaticRegisterNativesARaceAIPawn(); \
	friend struct Z_Construct_UClass_ARaceAIPawn_Statics; \
public: \
	DECLARE_CLASS(ARaceAIPawn, AWheeledVehicle, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RaceAI"), NO_API) \
	DECLARE_SERIALIZER(ARaceAIPawn)


#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARaceAIPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARaceAIPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARaceAIPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARaceAIPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARaceAIPawn(ARaceAIPawn&&); \
	NO_API ARaceAIPawn(const ARaceAIPawn&); \
public:


#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARaceAIPawn(ARaceAIPawn&&); \
	NO_API ARaceAIPawn(const ARaceAIPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARaceAIPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARaceAIPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARaceAIPawn)


#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(ARaceAIPawn, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(ARaceAIPawn, Camera); } \
	FORCEINLINE static uint32 __PPO__InternalCameraBase() { return STRUCT_OFFSET(ARaceAIPawn, InternalCameraBase); } \
	FORCEINLINE static uint32 __PPO__InternalCamera() { return STRUCT_OFFSET(ARaceAIPawn, InternalCamera); } \
	FORCEINLINE static uint32 __PPO__InCarSpeed() { return STRUCT_OFFSET(ARaceAIPawn, InCarSpeed); } \
	FORCEINLINE static uint32 __PPO__InCarGear() { return STRUCT_OFFSET(ARaceAIPawn, InCarGear); } \
	FORCEINLINE static uint32 __PPO__EngineSoundComponent() { return STRUCT_OFFSET(ARaceAIPawn, EngineSoundComponent); }


#define RaceAI_Source_RaceAI_RaceAIPawn_h_16_PROLOG
#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_PRIVATE_PROPERTY_OFFSET \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_SPARSE_DATA \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_RPC_WRAPPERS \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_INCLASS \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define RaceAI_Source_RaceAI_RaceAIPawn_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_PRIVATE_PROPERTY_OFFSET \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_SPARSE_DATA \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_INCLASS_NO_PURE_DECLS \
	RaceAI_Source_RaceAI_RaceAIPawn_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RACEAI_API UClass* StaticClass<class ARaceAIPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID RaceAI_Source_RaceAI_RaceAIPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
