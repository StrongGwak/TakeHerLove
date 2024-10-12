// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController() 
{
	ConstructorHelpers::FObjectFinder<UBehaviorTree>aiBeHavior(TEXT("BehaviorTree'/Game/BluePrint/C++BP/Enemy/BT_Enemy.BT_Enemy'"));

	if (aiBeHavior.Succeeded()) 
	{
		EnemyBehaviorTree = aiBeHavior.Object;
	}

	static ConstructorHelpers::FClassFinder<AActor>TempTarget(TEXT("/Game/BluePrint/Point/BP_Target.BP_Target_C"));
	if (TempTarget.Succeeded())
	{
		Target = TempTarget.Class;
	}

	static ConstructorHelpers::FClassFinder<AActor>TempFrontDoor(TEXT("/Game/BluePrint/Object/BP_FrontDoor.BP_FrontDoor_C"));
	if (TempFrontDoor.Succeeded())
	{
		FrontDoor = TempFrontDoor.Class;
	}

	static ConstructorHelpers::FClassFinder<AActor>TempSlideDoor(TEXT("/Game/BluePrint/Object/BP_SlideDoor.BP_SlideDoor_C"));
	if (TempSlideDoor.Succeeded())
	{
		SlideDoor = TempSlideDoor.Class;
	}

	static ConstructorHelpers::FClassFinder<AActor>TempBalconyDoor(TEXT("/Game/BluePrint/Object/BP_BalconyDoor.BP_BalconyDoor_C"));
	if (TempBalconyDoor.Succeeded())
	{
		BalconyDoor = TempBalconyDoor.Class;
	}

}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (EnemyBehaviorTree != nullptr) 
	{
		RunBehaviorTree(EnemyBehaviorTree);

		// BlackBoard Player 설정
		GetBlackboardComponent()->SetValueAsObject(TEXT("Player"), UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

		TArray<AActor*> FoundActors;
		// BlackBoard AI 이동 위치 설정
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), Target, FoundActors);
		for (int i = 0; i < FoundActors.Num(); i++) {
			FName Label = *FoundActors[i]->GetActorLabel();
			GetBlackboardComponent()->SetValueAsVector(Label, FoundActors[i]->GetActorLocation());
		}

		AActor* Door = Cast<AActor>(UGameplayStatics::GetActorOfClass(GetWorld(), FrontDoor));
		GetBlackboardComponent()->SetValueAsObject(TEXT("FrontDoor"), Door);

		FoundActors.Empty();
		// BlackBoard 문 오브젝트 설정
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), SlideDoor, FoundActors);
		for (int i = 0; i < FoundActors.Num(); i++) {
			FName Label = *FoundActors[i]->GetActorLabel();
			GetBlackboardComponent()->SetValueAsObject(Label, FoundActors[i]);
		}

		FoundActors.Empty();
		// BlackBoard 문 오브젝트 설정
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), BalconyDoor, FoundActors);
		for (int i = 0; i < FoundActors.Num(); i++) {
			FName Label = *FoundActors[i]->GetActorLabel();
			GetBlackboardComponent()->SetValueAsObject(Label, FoundActors[i]);
		}
		
	}

}

void AMyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorLocation());

	
}
