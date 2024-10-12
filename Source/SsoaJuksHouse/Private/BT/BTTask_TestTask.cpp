// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TestTask.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TestTask::UBTTask_TestTask()
{
	NodeName = "TestTask";
}

EBTNodeResult::Type UBTTask_TestTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsKnock"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToBalconyDoor"), true);

	return EBTNodeResult::Succeeded;
}
