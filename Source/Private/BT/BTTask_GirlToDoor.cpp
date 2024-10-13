// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GirlToDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_GirlToDoor::UBTTask_GirlToDoor()
{
	NodeName = "GirlToDoor";
}

EBTNodeResult::Type UBTTask_GirlToDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsGirlRoomTalk"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGirlBackDoor"), true);

	return EBTNodeResult::Succeeded;
}
