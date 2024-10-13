// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UMyAnimInstance::UMyAnimInstance()
{


}

//애니메이션이 생성될 때 호출
void UMyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Owner = Cast<ACharacter>(GetOwningActor());
	if (Owner) {
		Movement = Owner->GetCharacterMovement();
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Movement) {
		Velocity = Movement->Velocity;
		moveSpeed = Velocity.Size2D();
		isFalling = Movement->IsFalling();
		Angle = UAnimInstance::CalculateDirection(Velocity, Owner->GetActorRotation());
		FRotator MouseRotation = Owner->GetActorRotation() - Owner->GetControlRotation();
		MouseRotation.Normalize();
		AimRotation = FRotator(0, MouseRotation.Yaw, FMath::Clamp(MouseRotation.Pitch, -40, 40));
	}

}