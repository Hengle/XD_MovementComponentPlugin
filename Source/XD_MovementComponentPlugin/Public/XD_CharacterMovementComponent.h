﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "XD_MovementComponentType.h"
#include "XD_CharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class XD_MOVEMENTCOMPONENTPLUGIN_API UXD_CharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UXD_CharacterMovementComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void CustomMovingTick(float DeltaTime);

	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;
protected:
	void UpdateMovementSetting();

	float ChooseMaxWalkSpeed() const;

	float ChooseMaxWalkCrouchedSpeed() const;

	float ChooseMaxAcceleration() const;

	float ChooseBrakingDeceleration() const;

	float ChooseGroundFriction() const;

	float LookingDirectionWithOffsetYaw(float DeltaTime, float OffsetInterpSpeed, float NE, float NW, float SE, float SW, float Buffer);

	float CalculateRotationRate(float SlowSpeed, float SlowSpeedRate, float FastSpeed, float FastSpeedRate) const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	FVector GetVelocity() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	bool CanSprint() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	bool HasMovementInput() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	FRotator GetLastVelocityRotation() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	FRotator GetLastMovementInputRotation() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	bool IsMoving() const;
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnALS_MovementModeChanged, EALS_MovementMode, PreALS_MovementMode, EALS_MovementMode, ALS_MovementMode);
	UPROPERTY(BlueprintAssignable)
	FOnALS_MovementModeChanged OnALS_MovementModeChanged;
	void SetALS_MovementMode(EALS_MovementMode NewMovementMode);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInvokeGaitChanged, ECharacterGait, PreGait, ECharacterGait, Gait);
	UPROPERTY(BlueprintAssignable)
	FOnInvokeGaitChanged OnInvokeGaitChanged;
	void SetGait(ECharacterGait Value);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStanceStateChanged, ECharacterStanceState, PreStanceState, ECharacterStanceState, StanceState);
	UPROPERTY(BlueprintAssignable)
	FOnStanceStateChanged OnStanceStateChanged;
	void SetStanceState(ECharacterStanceState Value);

	virtual void Crouch(bool bClientSimulation) override;

	virtual void UnCrouch(bool bClientSimulation)  override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRotationModeChanged, ECharacterRotationMode, PreRotationMode, ECharacterRotationMode, RotationMode);
	UPROPERTY(BlueprintAssignable)
	FOnRotationModeChanged OnRotationModeChanged;
	void SetRotationMode(ECharacterRotationMode Value);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS State Values")
	ECharacterGait InvokeGait;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS State Values")
	ECharacterStanceState StanceState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS State Values")
	uint8 bAiming : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS State Values")
	EALS_MovementMode ALS_MovementMode = EALS_MovementMode::Grounded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS State Values")
	ECharacterRotationMode RotationMode = ECharacterRotationMode::LookingDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Essential Variables")
	FRotator LookingRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Essential Variables")
	float AimYawDelta;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Essential Variables")
	float AimYawRate;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	uint8 bShouldSprint : 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	uint8 bCanSprint : 1;
public:
	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	FVector GetMovementInput() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	FRotator GetCharacterRotation() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	void SetCharacterRotation(const FRotator& Rotation);

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	float GetMovementInputVelocityDifference() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	float GetTargetCharacterRotationDifference() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	float GetDirection() const;

	UFUNCTION(BlueprintCallable, Category = "Character Movement")
	class ACharacter* GetCharacterOwing() const;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Rotation System")
	ECardinalDirection CardinalDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Rotation System")
	FRotator TargetRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Rotation System")
	float RotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Rotation System")
	float RotationRateMultiplier;

	//Config
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Walk")
	float WalkingSpeed = 165.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Run")
	float RunningSpeed = 375.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Sprint")
	float SprintingSpeed = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Crouch")
	float CrouchingSpeed = 150.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Crouch")
	float CrouchingSprintingSpeed = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Walk")
	float WalkingAcceleration = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Run")
	float RunningAcceleration = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Walk")
	float WalkingDeceleration = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Run")
	float RunningDeceleration = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Walk")
	float WalkingGroundFriction = 8.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Movement: Run")
	float RunningGroundFriction = 6.f;
};
