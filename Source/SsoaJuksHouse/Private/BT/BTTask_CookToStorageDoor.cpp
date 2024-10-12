// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_CookToStorageDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_CookToStorageDoor::UBTTask_CookToStorageDoor()
{
	NodeName = "CookToStorageDoor";
}

EBTNodeResult::Type UBTTask_CookToStorageDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsCook"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToStorageDoor"),true);

	return EBTNodeResult::Succeeded;
}
