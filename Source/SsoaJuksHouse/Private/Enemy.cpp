// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> TempMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/rp_carla_rigged_001_ue4.rp_carla_rigged_001_ue4'"));
	if (TempMesh.Succeeded()) 
	{
		GetMesh()->SetSkeletalMesh(TempMesh.Object);
		GetMesh()->SetWorldLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstance(TEXT("/Game/BluePrint/C++BP/Enemy/ABP_EnemyAnimation.ABP_EnemyAnimation_C"));
	if (AnimInstance.Succeeded()) 
	{
		GetMesh()->SetAnimInstanceClass(AnimInstance.Class);
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> TalkAM(TEXT("/Script/Engine.AnimMontage'/Game/Animation/EnemyAni/AM_Talk.AM_Talk'"));
	if (TalkAM.Succeeded())
	{
		Talk = TalkAM.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> Talk2AM(TEXT("/Script/Engine.AnimMontage'/Game/Animation/EnemyAni/AM_Talk2.AM_Talk2'"));
	if (Talk2AM.Succeeded())
	{
		Talk2 = Talk2AM.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> Talk3AM(TEXT("/Script/Engine.AnimMontage'/Game/Animation/EnemyAni/AM_Talk3.AM_Talk3'"));
	if (Talk3AM.Succeeded())
	{
		Talk3 = Talk3AM.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> TerrifieAM(TEXT("/Script/Engine.AnimMontage'/Game/Animation/EnemyAni/AM_Terrifie.AM_Terrifie'"));
	if (TerrifieAM.Succeeded())
	{
		Terrifie = TerrifieAM.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> ThanksAM(TEXT("/Script/Engine.AnimMontage'/Game/Animation/EnemyAni/AM_Thanks.AM_Thanks'"));
	if (ThanksAM.Succeeded())
	{
		Thanks = ThanksAM.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> ThinkAM(TEXT("/Script/Engine.AnimMontage'/Game/Animation/EnemyAni/AM_Think.AM_Think'"));
	if (ThinkAM.Succeeded())
	{
		Think = ThinkAM.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> HelloAM(TEXT("/Script/Engine.AnimMontage'/Game/Animation/EnemyAni/AM_Hello.AM_Hello'"));
	if (HelloAM.Succeeded())
	{
		Hello = HelloAM.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> AngryAM(TEXT("/Script/Engine.AnimMontage'/Game/Animation/EnemyAni/AM_Angry.AM_Angry'"));
	if (AngryAM.Succeeded())
	{
		Angry = AngryAM.Object;
	}
	
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}