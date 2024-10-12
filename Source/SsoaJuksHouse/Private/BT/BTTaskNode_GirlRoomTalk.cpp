// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_GirlRoomTalk.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTaskNode_GirlRoomTalk::UBTTaskNode_GirlRoomTalk()
{
	NodeName = "GrandMotherRoomTalk";
}

EBTNodeResult::Type UBTTaskNode_GirlRoomTalk::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGirl"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsGirlRoomTalk"), true);

	return EBTNodeResult::Succeeded;
}
