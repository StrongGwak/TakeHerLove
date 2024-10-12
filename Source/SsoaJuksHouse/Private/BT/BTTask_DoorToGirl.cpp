// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DoorToGirl.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_DoorToGirl::UBTTask_DoorToGirl()
{
	NodeName = "DoorToGirl";
}

EBTNodeResult::Type UBTTask_DoorToGirl::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGirlDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToGirl"), true);

	return EBTNodeResult::Succeeded;
}

