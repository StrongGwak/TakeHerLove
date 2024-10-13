// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_DoorToBalcony.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_DoorToBalcony::UBTTask_DoorToBalcony()
{
	NodeName = "DoorToBalcony";
}

EBTNodeResult::Type UBTTask_DoorToBalcony::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	BlackboardComp->SetValueAsBool(TEXT("IsMoveToBalconyDoor"), false);
	BlackboardComp->SetValueAsBool(TEXT("IsMoveToBalcony"), true);

	return EBTNodeResult::Succeeded;
}

