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

//���� �ð��� ������ ���¸� Move�� ��ȯ�ϰ� �ʹ�.
void UEnemyFSM::IdleState()
{
    //���� �ð��� ������ ���¸� Move�� ��ȯ�ϰ� �ʹ�.
    //�ð��� �귶����
    CurrentTime += GetWorld()->DeltaRealTimeSeconds;
    //�����ð��� ��������
    if (CurrentTime > IdleTime) {
        //���¸� Move�� ��ȯ�Ѵ�.
        mState = EEnemyState::MOVE;
        CurrentTime = 0;
    }
}

//Ÿ�� �������� �����̰� �ʹ�.
void UEnemyFSM::MoveState()
{
    //FVector Direction = Target->GetActorLocation() - Me->GetActorLocation();
    //float Distance = Direction.Size();
    //// ������ �ʿ��ϴ�
    //Direction.Normalize();
    //// �̵��ϰ� �ʹ�
    //FVector P = Me->GetActorLocation() + Direction * Speed * GetWorld()->DeltaRealTimeSeconds;
    //Me->SetActorLocation(P);

    //// Ʈ������ ���� ����
    //// ���ݹ��� �ȿ� ������ ���¸� �������� ��ȯ�ϰ� �ʹ�.
    //// �Ÿ��� ���ؾ� �Ѵ�.
    //// ���ݹ��� �ȿ� �������ϱ�
    //if (Distance < AttackRange) {
    //    // ���¸� �������� ��ȯ�ϰ� �ʹ�.
    //    mState = EEnemyState::ATTACK;
    //}
}

// ���� �ð��� �ѹ��� �����ϰ� �ʹ�.
void UEnemyFSM::AttackState()
{
    // �ð��� �귶���ϱ�
    //CurrentTime += GetWorld()->DeltaRealTimeSeconds;
    //// ���� �ð��� �����ϱ�
    //if (CurrentTime > AttackTime) {
    //    // �����ϰ�ʹ�.
    //    //UE_LOG(LogTemp, Warning, TEXT("����!!!"));
    //    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, "Attack");
    //    CurrentTime = 0;
    //}

    //// Ÿ���� �������� ���¸� �̵����� ��ȯ�ϰ� �ʹ�.
    //// -> Ÿ���� ���ݹ����� �����
    //float Distance = FVector::Dist(Target->GetActorLocation(), Me->GetActorLocation());
    //if (Distance > AttackRange) {
    //    // ���¸� �̵����� ��ȯ
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
