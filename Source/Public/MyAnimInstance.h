// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UMyAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override; //애니메이션이 생성되면 호출되는 함수

	virtual void NativeUpdateAnimation(float DeltaSeconds) override; //프레임마다 호출 함수

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class ACharacter* Owner; //Character Actor

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class UCharacterMovementComponent* Movement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	FVector Velocity; //Movement에 velocity 속력을 저장

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float moveSpeed; //길이를 저장

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	bool isFalling = false; //Ground에 닿여 있는지에 대한 여부

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	FRotator AimRotation;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	bool isEquip = false; //무기 장착

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	bool isAim = false; //조준

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float Angle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	bool bIgnoreInput = false;
	
};
