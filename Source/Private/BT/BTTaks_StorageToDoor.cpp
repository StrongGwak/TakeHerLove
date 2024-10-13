// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaks_StorageToDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTaks_StorageToDoor::UBTTaks_StorageToDoor()
{
	NodeName = "Delete";
}

EBTNodeResult::Type UBTTaks_StorageToDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToStorage"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToStorageBackDoor"), true);

	return EBTNodeResult::Succeeded;
}
