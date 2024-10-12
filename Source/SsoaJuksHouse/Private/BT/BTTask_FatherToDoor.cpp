// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FatherToDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FatherToDoor::UBTTask_FatherToDoor()
{
	NodeName = "FatherToDoor";
}

EBTNodeResult::Type UBTTask_FatherToDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsFatherRoomTalk"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToFatherBackDoor"), true);

	return EBTNodeResult::Succeeded;
}
