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
	virtual void NativeInitializeAnimation() override; //�ִϸ��̼��� �����Ǹ� ȣ��Ǵ� �Լ�

	virtual void NativeUpdateAnimation(float DeltaSeconds) override; //�����Ӹ��� ȣ�� �Լ�

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class ACharacter* Owner; //Character Actor

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	class UCharacterMovementComponent* Movement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	FVector Velocity; //Movement�� velocity �ӷ��� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float moveSpeed; //���̸� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	bool isFalling = false; //Ground�� �꿩 �ִ����� ���� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	FRotator AimRotation;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	bool isEquip = false; //���� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	bool isAim = false; //����

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	float Angle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
	bool bIgnoreInput = false;
	
};
