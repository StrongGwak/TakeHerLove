// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DoorToHole.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_DoorToHole::UBTTask_DoorToHole()
{
	NodeName = "DoorToHole";
}

EBTNodeResult::Type UBTTask_DoorToHole::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) 
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsKnock"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToHole"), true);

	return EBTNodeResult::Succeeded;
}
