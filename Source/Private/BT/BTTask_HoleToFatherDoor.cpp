// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_HoleToFatherDoor.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_HoleToFatherDoor::UBTTask_HoleToFatherDoor()
{
	NodeName = "HoleToFatherDoor";
}

EBTNodeResult::Type UBTTask_HoleToFatherDoor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsCorridorTalk"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToFatherDoor"), true);

	return EBTNodeResult::Succeeded;
}

