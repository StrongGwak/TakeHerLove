// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_StorageToDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_StorageToDoor::UBTTask_StorageToDoor()
{
	NodeName = "StorageToDoor";
}

EBTNodeResult::Type UBTTask_StorageToDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsStorageTalk"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToStorageBackDoor"), true);

	return EBTNodeResult::Succeeded;
}
