// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_FatherRoomTalk.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTaskNode_FatherRoomTalk::UBTTaskNode_FatherRoomTalk()
{
	NodeName = "FatherRoomTalk";
}

EBTNodeResult::Type UBTTaskNode_FatherRoomTalk::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToFather"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsFatherRoomTalk"), true);

	return EBTNodeResult::Succeeded;
}

