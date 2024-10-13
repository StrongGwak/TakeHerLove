// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFSM.h"
#include "kismet/GameplayStatics.h"
#include "Enemy.h"

// Sets default values for this component's properties
UEnemyFSM::UEnemyFSM()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyFSM::BeginPlay()
{
	Super::BeginPlay();

	// ...
	/*Me = Cast<AEnemy>(GetOwner());
	AActor* player = UGameplayStatics::GetActorOfClass(GetWorld(), PSGCCCharacter::StaticClass());
	Target = Cast<ATPSGCCCharacter>(player);*/
}


// Called every frame
void UEnemyFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
    FString stateStr = UEnum::GetValueAsString(mState);
    //UE_LOG(LogTemp, Warning, TEXT("Current Sate : %s"), *stateStr);

    switch (mState)
    {
    case EEnemyState::IDLE:
        IdleState();
        break;
    case EEnemyState::MOVE:
        MoveState();
        break;
    case EEnemyState::ATTACK:
        AttackState();
        break;
    case EEnemyState::DAMAGE:
        DamageState();
        break;
    case EEnemyState::DIE:
        DieState();
        break;
    }
}

//일정 시간이 지나면 상태를 Move로 전환하고 싶다.
void UEnemyFSM::IdleState()
{
    //일정 시간이 지나면 상태를 Move로 전환하고 싶다.
    //시간이 흘렀으니
    CurrentTime += GetWorld()->DeltaRealTimeSeconds;
    //일정시간이 지났으니
    if (CurrentTime > IdleTime) {
        //상태를 Move로 전환한다.
        mState = EEnemyState::MOVE;
        CurrentTime = 0;
    }
}

//타겟 방향으로 움직이고 싶다.
void UEnemyFSM::MoveState()
{
    //FVector Direction = Target->GetActorLocation() - Me->GetActorLocation();
    //float Distance = Direction.Size();
    //// 방향이 필요하다
    //Direction.Normalize();
    //// 이동하고 싶다
    //FVector P = Me->GetActorLocation() + Direction * Speed * GetWorld()->DeltaRealTimeSeconds;
    //Me->SetActorLocation(P);

    //// 트렌지션 조건 설정
    //// 공격범위 안에 들어오면 상태를 공격으로 전환하고 싶다.
    //// 거리를 구해야 한다.
    //// 공격범위 안에 들어왔으니까
    //if (Distance < AttackRange) {
    //    // 상태를 공격으로 전환하고 싶다.
    //    mState = EEnemyState::ATTACK;
    //}
}

// 일정 시간에 한번씩 공격하고 싶다.
void UEnemyFSM::AttackState()
{
    // 시간이 흘렀으니까
    //CurrentTime += GetWorld()->DeltaRealTimeSeconds;
    //// 일정 시간이 됐으니까
    //if (CurrentTime > AttackTime) {
    //    // 공격하고싶다.
    //    //UE_LOG(LogTemp, Warning, TEXT("공격!!!"));
    //    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, "Attack");
    //    CurrentTime = 0;
    //}

    //// 타겟이 도망가면 상태를 이동으로 전환하고 싶다.
    //// -> 타겟이 공격범위를 벗어나면
    //float Distance = FVector::Dist(Target->GetActorLocation(), Me->GetActorLocation());
    //if (Distance > AttackRange) {
    //    // 상태를 이동으로 전환
    //    mState = EEnemyState::MOVE;
    //}



}

void UEnemyFSM::OnDamageProcess()
{
    Me->Destroy();
}

void UEnemyFSM::DamageState()
{

}

void UEnemyFSM::DieState()
{

}
