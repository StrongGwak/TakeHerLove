// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_StorageTalk.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_StorageTalk::UBTTask_StorageTalk()
{
	NodeName = "StorageTalk";
}

EBTNodeResult::Type UBTTask_StorageTalk::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToStorage"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsStorageTalk"), true);

	return EBTNodeResult::Succeeded;
}
