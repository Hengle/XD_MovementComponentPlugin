﻿// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "XD_MovementComponentFunctionLibrary.generated.h"

class ACharacter;

UCLASS()
class XD_MOVEMENTCOMPONENTPLUGIN_API UXD_MovementComponentFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "移动")
	static FVector GetMovementInput(const ACharacter* Character);

	UFUNCTION(BlueprintPure, Category = "移动")
	static FVector GetPathFollowingInput(const ACharacter* Character);
};
