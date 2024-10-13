// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DoorToStorage.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_DoorToStorage::UBTTask_DoorToStorage()
{
	NodeName = "DoorToStorage";
}

EBTNodeResult::Type UBTTask_DoorToStorage::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToStorageDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToStorage"), true);

	return EBTNodeResult::Succeeded;
}
