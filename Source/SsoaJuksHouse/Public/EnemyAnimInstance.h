// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SSOAJUKSHOUSE_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UEnemyAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override; // �ִϸ��̼��� �����Ǹ� ȣ��Ǵ� �Լ�

	virtual void NativeUpdateAnimation(float DeltaSeconds) override; // �����Ӹ��� ȣ�� �Լ�

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	class ACharacter* Owner; //Character Actor

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	class UCharacterMovementComponent* Movement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	FVector Velocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	float MoveSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	FRotator Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	float Angle;
	
};
