﻿// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "XD_MovementComponentFunctionLibrary.h"
#include <GameFramework/Character.h>

FVector UXD_MovementComponentFunctionLibrary::GetMovementInput(const ACharacter* Character)
{
	return Character ? Character->GetCharacterMovement()->GetCurrentAcceleration().GetSafeNormal() : FVector::ZeroVector;
}

FVector UXD_MovementComponentFunctionLibrary::GetPathFollowingInput(const ACharacter* Character)
{
	return Character ? Character->GetCharacterMovement()->RequestedVelocity.GetSafeNormal() : FVector::ZeroVector;
}
