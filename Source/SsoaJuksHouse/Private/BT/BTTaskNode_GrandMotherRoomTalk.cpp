// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_GrandMotherRoomTalk.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTaskNode_GrandMotherRoomTalk::UBTTaskNode_GrandMotherRoomTalk()
{
	NodeName = "GrandMotherRoomTalk";
}

EBTNodeResult::Type UBTTaskNode_GrandMotherRoomTalk::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGrandMother"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsGrandMotherRoomTalk"), true);

	return EBTNodeResult::Succeeded;
}
