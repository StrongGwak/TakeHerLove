// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CorridorTalk.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_CorridorTalk::UBTTask_CorridorTalk()
{
	NodeName = "CorridorTalk";
}

EBTNodeResult::Type UBTTask_CorridorTalk::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToHoleFromStorage"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsCorridorTalk"), true);

	return EBTNodeResult::Succeeded;
}