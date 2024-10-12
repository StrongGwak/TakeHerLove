// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_StorageToHole.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_StorageToHole::UBTTask_StorageToHole()
{
	NodeName = "StorageToHole";
}

EBTNodeResult::Type UBTTask_StorageToHole::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToStorageBackDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToHoleFromStorage"), true);

	return EBTNodeResult::Succeeded;
}

