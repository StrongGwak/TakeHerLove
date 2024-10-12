// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DoorToFather.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_DoorToFather::UBTTask_DoorToFather()
{
	NodeName = "DoorToFather";
}

EBTNodeResult::Type UBTTask_DoorToFather::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToFatherDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToFather"), true);

	return EBTNodeResult::Succeeded;
}
